#include<iostream>
#include<fstream>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<sstream>

using namespace std;

void print_seeds(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nf, int n){

	cout<<"  *seed"<<endl; //print statement => denotes the beginning of seed field
	int bf1;
	int be1;
	vector<float> vxp;
	vector<float> vyp;
	vector<float> vzp;
	float xmaxp;
	float xminp;
	float ymaxp;
	float yminp;
	float zmaxp;
	float zminp;

	for(int i=0;i<n;i++){
		bf1 = polyhedron[i].size()-1;
		for(int j=1;j<=bf1;j++){
			int be1 = facet[i].size()-1;
			for(int k=1;k<=be1;k++){
				for(int m=1;m<=2;m++){
					vxp.push_back(node[edge[facet[polyhedron[i][j]-1][k]-1][m]-1][1]);
					vyp.push_back(node[edge[facet[polyhedron[i][j]-1][k]-1][m]-1][2]);
					vzp.push_back(node[edge[facet[polyhedron[i][j]-1][k]-1][m]-1][3]);
				}
			}

		}
		//print statement for that seed shall come here
		xmaxp = *max_element(vxp.begin(), vxp.end());
		// cout<<xmaxp<<"it is";
		xminp = *min_element(vxp.begin(), vxp.end());
		// cout<<xminp<<"it is";
		ymaxp = *max_element(vyp.begin(), vyp.end());
		// cout<<ymaxp<<"it is";

		yminp = *min_element(vyp.begin(), vyp.end());
		zmaxp = *max_element(vzp.begin(), vzp.end());
		zminp = *min_element(vzp.begin(), vzp.end());

		cout<<"   "<<i+1<<" "<<(xminp+xmaxp)/2<<" "<<(yminp+ymaxp)/2<<" "<<(zminp+zmaxp)/2<<" 0"<<endl;
		vxp.clear();
		vyp.clear();
		vzp.clear();
	}
	return;
}

void print_vertices(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nv){

	cout<<" **vertex"<<endl;//print statement => denotes the beginning of vertex field
	cout<<" "<<nv<<endl; //number of vertices => they are 12 in number for our given problem
	cout<<"   ";
	//printing the (x, y, z) coordinates of all the 12 vertices
	for(int i=0;i<nv;i++){
		cout<<i+1;
		for(int j=1;j<=3;j++){
			if(j==1){
				cout<<" ";
			}
			cout<<node[i][j]<<" ";
		}
		cout<<"0";
		cout<<endl;
		if(i!=nv-1) {cout<<"   ";}
	}

	return;
}

void print_edges(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int ne){
	cout<<" **edge"<<endl; //print statement => denotes the beginning of edge field
	cout<<" "<<ne<<endl; //number of edges ; they are 12 in number for our given problem
	cout<<"   ";
	//printing the endpoits of the edges along with edge_state which is 0 by default
	for(int i=0;i<ne;i++){
		cout<<i+1;
		for(int j=1;j<=2;j++){
			if(j==1){
				cout<<" ";
			}
			cout<<edge[i][j]<<" ";
		}
		cout<<"0";
		cout<<endl;
		if(i!=ne-1) {cout<<"   ";}
	}
	return;
}

void plane_params(float x1, float y1, float z1, float x2,float y2, float z2, float x3, float y3, float z3){
	vector<double> v1;
	float a1 = x2 - x1;
    float b1 = y2 - y1;
    float c1 = z2 - z1;
    float a2 = x3 - x1;
    float b2 = y3 - y1;
    float c2 = z3 - z1;
    float a = b1 * c2 - b2 * c1;
    float b = a2 * c1 - a1 * c2;
    float c = a1 * b2 - b1 * a2;
    float d = ( a * x1 + b * y1 + c * z1);
    v1.push_back(d);
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    float norm = sqrt((a*a)+(b*b)+(c*c));
    // cout<<"The size of v1 vector is: "<<v1.size();
    for(int i=0;i<v1.size();i++){
    	v1[i] = v1[i]/norm;
    }
    cout<<"    ";
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}

	return;
}

void print_face_description(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nf){
	cout<<" **face"<<endl;
	//cout<<"hello there";
	int nc;
	cout<<" "<<nf<<endl;
	for(int i=1;i<=nf;i++){
		nc = facet[i-1].size()-1;
		// cout<<"i is:"<<i<<endl;
		// cout<<"nc is:"<<facet[i-1].size()-1<<endl;
		cout<<"   "<<i<<" "<<nc<<" ";

		//Algorithm to print the edges in CCW and with sign
		vector<int> edgeWithSign;
		if(nc%2==0){
			for(int j=1;j<=nc-1;j=j+2){
				// cout<<"this is edge 1: "<<edge[facet[i-1][j]-1][2];
				// cout<<"this is edge 2: "<<edge[facet[i-1][j+1]-1][1];
				// break;
				// cout<<"the value of j is:"<<j<<endl;
				if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][1]){ //a2=b1
					// cout<<"IF 1"<<endl;
					edgeWithSign.push_back(facet[i-1][j]);
					// cout<<"pushin back "<<facet[i-1][j]<<endl;
					edgeWithSign.push_back(facet[i-1][j+1]);
					// cout<<"pushin back "<<facet[i-1][j+1]<<endl;
					// cout<<"this is edge 1: "<<facet[i-1][j];
				 //    cout<<"this is edge 2: "<<facet[i-1][j+1];

				}
				else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][2]){ //a1=b2
					// cout<<"IF 2"<<endl;
					edgeWithSign.push_back(-facet[i-1][j]);
					// cout<<"pushin back "<<-facet[i-1][j]<<endl;
					edgeWithSign.push_back(-facet[i-1][j+1]);
					// cout<<"pushin back "<<-facet[i-1][j+1]<<endl;
				}
				else if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][2]){ //a2=b2
					// cout<<"IF 3"<<endl;
					edgeWithSign.push_back(facet[i-1][j]);
					// cout<<"pushin back "<<facet[i-1][j]<<endl;
					edgeWithSign.push_back(-facet[i-1][j+1]);
					// cout<<"pushin back "<<-facet[i-1][j+1]<<endl;
				}
				else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][1]){ //a1=b1
					// cout<<"IF 4"<<endl;
					edgeWithSign.push_back(-facet[i-1][j]);
					// cout<<"pushin back "<<-facet[i-1][j]<<endl;
					edgeWithSign.push_back(facet[i-1][j+1]);
					// cout<<"pushin back "<<facet[i-1][j+1]<<endl;
				}
				
			}
		}
		else if (nc%2!=0){
			for(int j=1;j<=nc;j=j+2){
				// cout<<"this is edge 1: "<<edge[facet[i-1][j]-1][2];
				// cout<<"this is edge 2: "<<edge[facet[i-1][j+1]-1][1];
				// break;
				if(j==nc){
					if(edge[facet[i-1][j-1]-1][2]==edge[facet[i-1][j]-1][1]){ //a2=b1
						edgeWithSign.push_back(facet[i-1][j]);
						// cout<<"this is edge 1: "<<facet[i-1][j];
					 //    cout<<"this is edge 2: "<<facet[i-1][j+1];

					}
					else if(edge[facet[i-1][j-1]-1][1]==edge[facet[i-1][j]-1][2]){ //a1=b2
						edgeWithSign.push_back(-facet[i-1][j]);
						
					}
					else if(edge[facet[i-1][j-1]-1][2]==edge[facet[i-1][j]-1][2]){ //a2=b2
						edgeWithSign.push_back(-facet[i-1][j]);
						
					}
					else if(edge[facet[i-1][j-1]-1][1]==edge[facet[i-1][j]-1][1]){ //a1=b1
						edgeWithSign.push_back(facet[i-1][j]);
						
					}
				}
				else{
					if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][1]){ //a2=b1
						edgeWithSign.push_back(facet[i-1][j]);
						edgeWithSign.push_back(facet[i-1][j+1]);
						// cout<<"this is edge 1: "<<facet[i-1][j];
					 //    cout<<"this is edge 2: "<<facet[i-1][j+1];

					}
					else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][2]){ //a1=b2
						edgeWithSign.push_back(-facet[i-1][j]);
						edgeWithSign.push_back(-facet[i-1][j+1]);
					}
					else if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][2]){ //a2=b2
						edgeWithSign.push_back(facet[i-1][j]);
						edgeWithSign.push_back(-facet[i-1][j+1]);
					}
					else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][1]){ //a1=b1
						edgeWithSign.push_back(-facet[i-1][j]);
						edgeWithSign.push_back(facet[i-1][j+1]);
					}
				}
			}
		}
		//cout<<endl;
//------//Algorithm to print edges finished//---------------------------------------------------

//------//Algorithm to print vertices in CCW//--------------------------------------------------
		vector<float> vertrep;
		vector<float> vertnorep;
		for(int p = 0;p<edgeWithSign.size();p++){
			// cout<<"size of edge vector"<<edgeWithSign.size();
			if(edgeWithSign[p]>0){
				vertrep.push_back(edge[edgeWithSign[p]-1][1]);
				vertrep.push_back(edge[edgeWithSign[p]-1][2]);
			}
			else{
				vertrep.push_back(edge[-edgeWithSign[p]-1][2]);
				vertrep.push_back(edge[-edgeWithSign[p]-1][1]);
			}
		}

		for(int itr = 0; itr<vertrep.size()-1;){
			// cout<<vertrep[itr]<<"hi";
			vertnorep.push_back(vertrep[itr]);
			if(vertrep[itr]==vertrep[itr+1]){
				itr = itr+2;
			}
			else{
				itr = itr+1;
			}
		}

		for(int p=0;p<vertnorep.size();p++){
			// cout<<"the size of vertices vectors is:"<<vertnorep.size();
			cout<<vertnorep[p]<<" ";
		}
		cout<<endl;
		cout<<"     "<<nc<<" ";
		
		for(int p =0;p<edgeWithSign.size();p++){
			cout<<edgeWithSign[p]<<" ";
		}
		edgeWithSign.clear();
		vertrep.clear();
		vertnorep.clear();
//------//Algorithm to print vertices in CCW manner finished//---------------------------


		cout<<endl;


//------//Algorithm to print equation of plane of the face//------------------------------
		// source: https://www.geeksforgeeks.org/program-to-find-equation-of-a-plane-passing-through-3-points/
		int x11 = vertnorep[0]-1;
		int y11 = x11;
		int z11 = x11;
		int x21 = vertnorep[1]-1;
		int y21 = x21;
		int z21 = x21;
		int x31 = vertnorep[2]-1;
		int y31 = x31;
		int z31 = y31;
		// cout<<"hello i m here u where "<< node[x11][1];
		float x1 = node[x11][1];
		float y1 = node[y11][2];
		float z1 = node[z11][3];
		float x2 = node[x21][1];
		float y2 = node[y21][2];
		float z2 = node[z21][3];
		float x3 = node[x31][1];
		float y3 = node[y31][2];
		float z3 = node[z31][3];

		plane_params(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		// bring the parameters in direction cosine form
		
		cout<<endl;

//------//Algorithm to print equation of plane of the face finished//---------------------


		cout<<"     0 0 0 0 0"<<endl; //print line
		
		
		// plane_param_vector.clear();

	}

	return;
} 

void print_polyhedron(vector<vector<int> > polyhedron, int n){
    cout<<" **polyhedron"<<endl<<" "<<n<<endl;
    map<int,int> dict;
    vector<vector<int> > newPoly; 
    
    for (int current =0;current<n;current++)
    {
        // cout<<2<<endl;
        // vector<int> vect1;
        // newPoly.push_back();
        vector<int > vect1;
        for (int face=1;face<polyhedron[current].size()+1;face++)
        {
            if (dict[polyhedron[current][face]]==0)
            {
                dict[polyhedron[current][face]]=1;
                // newPoly[current].push_back(polyhedron[current][face]);
                vect1.push_back(polyhedron[current][face]);

                // c(polyhedron[current][face]);
            }
            else 
            {
                vect1.push_back(-polyhedron[current][face]);
                // c(-polyhedron[current][face]);
            }
        }
        cout<<"   "<<current+1<<" "<<polyhedron[current].size()-1<<" ";
        for(int i=0;i<vect1.size()-1;i++){
        	cout<<vect1[i]<<" ";

        }cout<<endl;
        vect1.clear();

    }
    
    // for (int current = 0;current<newPoly.size();current++)
    // {
    //     cout<<"   "<<current+1<<" ";
    //     for (int face=0;face<newPoly[current].size()-1;face++)
    //     {
    //         cout<<newPoly[current][face]<<" ";
    //     }
    //     cout<<endl;
    // }
    return ;
}


void print_dom_vertices(int xmax, int xmin, int ymax, int ymin, int zmax, int zmin, float tolerance){
	cout<<"  *vertex"<<endl; //domain vertices
	cout<<"   "<<8<<endl;

	cout<<"   "<<1<<"  "<<xmin-tolerance<<" "<<ymin-tolerance<<" "<<zmin-tolerance<<" ver"<<1<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<2<<"  "<<xmax+tolerance<<" "<<ymin-tolerance<<" "<<zmin-tolerance<<" ver"<<2<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<3<<"  "<<xmax+tolerance<<" "<<ymax+tolerance<<" "<<zmin-tolerance<<" ver"<<3<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<4<<"  "<<xmin-tolerance<<" "<<ymax+tolerance<<" "<<zmin-tolerance<<" ver"<<4<<endl;
	cout<<"     "<<1<<" "<<1<<endl;

	cout<<"   "<<5<<"  "<<xmin-tolerance<<" "<<ymin-tolerance<<" "<<zmin+tolerance<<" ver"<<1<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<6<<"  "<<xmax-tolerance<<" "<<ymin+tolerance<<" "<<zmin+tolerance<<" ver"<<2<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<7<<"  "<<xmax+tolerance<<" "<<ymax+tolerance<<" "<<zmin+tolerance<<" ver"<<3<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<8<<"  "<<xmin+tolerance<<" "<<ymax-tolerance<<" "<<zmin+tolerance<<" ver"<<4<<endl;
	cout<<"     "<<1<<" "<<1<<endl;



	return;
}

void print_dom_edges(){
	cout<<"  *edge"<<endl;
	cout<<"   12"<<endl;

	cout<<"   1 2 2 1"<<endl;
	cout<<"     e1"<<endl;
	cout<<"     0"<<endl;

	cout<<"   2 2 3 2"<<endl;
	cout<<"     e2"<<endl;
	cout<<"     0"<<endl;

	cout<<"   3 2 4 3"<<endl;
	cout<<"     e3"<<endl;
	cout<<"     0"<<endl;

	cout<<"   4 2 1 4"<<endl;
	cout<<"     e4"<<endl;
	cout<<"     0"<<endl;

	cout<<"   5 2 4 5"<<endl;
	cout<<"     e5"<<endl;
	cout<<"     0"<<endl;

	cout<<"   6 2 5 8"<<endl;
	cout<<"     e6"<<endl;
	cout<<"     0"<<endl;

	cout<<"   7 2 8 1"<<endl;
	cout<<"     e7"<<endl;
	cout<<"     0"<<endl;

	cout<<"   8 2 7 2"<<endl;
	cout<<"     e8"<<endl;
	cout<<"     0"<<endl;

	cout<<"   9 2 8 7"<<endl;
	cout<<"     e9"<<endl;
	cout<<"     0"<<endl;

	cout<<"   10 2 6 5"<<endl;
	cout<<"     e10"<<endl;
	cout<<"     0"<<endl;

	cout<<"   11 2 3 6"<<endl;
	cout<<"     e11"<<endl;
	cout<<"     0"<<endl;

	cout<<"   12 2 6 7"<<endl;
	cout<<"     e12"<<endl;
	cout<<"     0"<<endl;

	return;
}

void print_dom_faces(int xmax, int xmin, int ymax, int ymin, int zmax, int zmin, float tolerance){
	cout<<" *face"<<endl;
	cout<<"   6"<<endl;

	cout<<"   1 4 6 5 8 7"<<endl;
	cout<<"     4 10 6 9 12"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<xmin-tolerance<<" -1 0 0"<<endl;
	cout<<"     f1"<<endl;
	cout<<"     0"<<endl;

	cout<<"   2 4 3 6 7 2"<<endl;
	cout<<"     4 11 12 8 2"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<xmax+tolerance<<" 1 0 0"<<endl;
	cout<<"     f2"<<endl;
	cout<<"     0"<<endl;

	cout<<"   3 4 3 2 1 4"<<endl;
	cout<<"     4 2 1 4 3"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<ymin-tolerance<<" 0 -1 0"<<endl;
	cout<<"     f3"<<endl;
	cout<<"     0"<<endl;

	cout<<"   4 4 4 1 8 5"<<endl;
	cout<<"     4 4 7 6 5"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<ymax+tolerance<<" 0 1 0"<<endl;
	cout<<"     f4"<<endl;
	cout<<"     0"<<endl;

	cout<<"   5 4 2 7 8 1"<<endl;
	cout<<"     4 8 9 7 1"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<zmin-tolerance<<" 0 0 -1"<<endl;
	cout<<"     f5"<<endl;
	cout<<"     0"<<endl;

	cout<<"   6 4 3 4 5 6"<<endl;
	cout<<"     4 3 5 10 11"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<zmax+tolerance<<" 0 0 1"<<endl;
	cout<<"     f6"<<endl;
	cout<<"     0"<<endl;

	return;
}

int main(int argc, char const *argv[])
{
	int d;
	cout<<"We can generate tesselation files for 2D and 3D tesselation."<<endl;
	cout<<"Please enter the value of which type of tesselation you want to generate."<<endl;
	cout<<"2 for 2D tesselation"<<endl;
	cout<<"3 for 3D tesselation"<<endl;

	cin>>d;

	if(d==2){

		ifstream inputFile0;
	    inputFile0.open("filenames_2d.txt");
	    vector<vector<string> > names;
	    string line0 = "";

	    while(getline(inputFile0, line0)){
		    // int nodeId;
		    string nodefile;
		    string edgefile;
		    string facetfile;
		    string polyhedronfile;
		    vector<string> row0;

		    

		    stringstream inputString(line0);

		    string tempString01;
		    getline(inputString, tempString01, ' ');
		    row0.push_back(tempString01);

		    string tempString02;
		    getline(inputString, tempString02, ' ');
		    row0.push_back(tempString02);

		    string tempString03;
		    getline(inputString, tempString03, ' ');
		    row0.push_back(tempString03);

		    // string tempString04;
		    // getline(inputString, tempString04, ' ');
		    // row0.push_back(tempString04);

		    names.push_back(row0);

		    line0 = "";
	  	}
		//reading node csv file into a vector of vectors
		ifstream inputFile;
	    inputFile.open(names[0][0]);
	    vector<vector<double> > node;
	    string line1 = "";

	    while(getline(inputFile, line1)){
		    int nodeId;
		    double xcord;
		    double ycord;
		    double zcord;
		    double weight;
		    vector<double> row;

		    

		    stringstream inputString(line1);

		    string tempString1;
		    getline(inputString, tempString1, ',');
		    nodeId = atoi(tempString1.c_str());
		    row.push_back(nodeId);

		    // tempString = "";
		    // stringstream inputString(line2);
		    string tempString2;
		    getline(inputString, tempString2, ',');
		    xcord = atof(tempString2.c_str());
		    row.push_back(xcord);

		    // tempString = "";
		    // stringstream inputString(line3);
		    string tempString3;
		    getline(inputString, tempString3, ',');
		    ycord = atof(tempString3.c_str());
		    row.push_back(ycord);

		    // tempString = "";
		    // stringstream inputString(line4);
		    string tempString4;
		    getline(inputString, tempString4, ',');
		    zcord = atof(tempString4.c_str());
		    row.push_back(zcord);

		    node.push_back(row);

		    line1 = "";
	  	}


	  	//reading edge csv file into a vector of vectors
	  	ifstream inputFile2;
	    inputFile2.open(names[1][0]);
	    vector<vector<int> > edge;
	    string line2 = "";

	    while(getline(inputFile2, line2)){
		    int edgeId;
		    int ecord1;
		    int ecord2;
		    double weight2;
		    vector<int> row2;

		    

		    stringstream inputString(line2);

		    string tempString12;
		    getline(inputString, tempString12, ',');
		    edgeId = atoi(tempString12.c_str());
		    row2.push_back(edgeId);

		    // tempString = "";
		    // stringstream inputString(line2);
		    string tempString22;
		    getline(inputString, tempString22, ',');
		    ecord1 = atoi(tempString22.c_str());
		    row2.push_back(ecord1);

		    // tempString = "";
		    // stringstream inputString(line3);
		    string tempString32;
		    getline(inputString, tempString32, ',');
		    ecord2 = atoi(tempString32.c_str());
		    row2.push_back(ecord2);

		    // tempString = "";
		    // stringstream inputString(line4);
		    string tempString42;
		    getline(inputString, tempString42, ',');
		    weight2 = atoi(tempString42.c_str());
		    row2.push_back(weight2);

		    edge.push_back(row2);

		    line2 = "";
	  	}

	  	

	  	//reading facet csv file into a vector of vectors
	  	ifstream inputFile3;
	    inputFile3.open(names[2][0]);
	    vector<vector<int> > facet;
	    string line3 = "";

	    while(getline(inputFile3, line3)){
		    int facetId;
		    int num_ed;
		    vector<int> row3;

		    stringstream inputString(line3);


		    string tempString13;
		    getline(inputString, tempString13, ',');
		    facetId = atoi(tempString13.c_str());
		    row3.push_back(facetId);

		    string tempString23;
		    getline(inputString, tempString23, ',');
		    num_ed = atoi(tempString23.c_str());
		    // cout<<num_ed<<"||";
		    
		    int u = 1;
		    int e;
		    string tempstring33;

		    while(u<=num_ed){
		    	e = 0;
		    	tempstring33 = "";
		    	getline(inputString, tempstring33, ',');
		    	e = atoi(tempstring33.c_str());
		    	row3.push_back(e);
		    	u++;
		    }


		    facet.push_back(row3);

		    line3 = "";
	  	}

	  	// for (int i = 0; i < facet.size(); i++)
	   //  {
	   //      for (int j = 0; j < facet[i].size(); j++)
	   //      {
	   //          cout << facet[i][j] << " ";
	   //      }   
	   //      cout << endl;
	   //  }

	    int n = facet.size();
	    // cout<<"the number of cells are :"<<n;

	    int nv = node.size();
	    // cout<<"the number of nodes are :"<<nv;

	    //we are always definining domain to be a square
	    int ndomver = 4;
		int ndomedge = 4;

		int ne = edge.size();
	    // cout<<"the number of edges are :"<<ne;

	    int nf = facet.size();
	    // cout<<"the number of facets are :"<<nf;

	    int nc;
	    // nc = facet[0].size();
	    // cout<<"row lenght"<<nc<<endl;

		freopen("output_2d.tess", "w", stdout); //write into output2.txt
		// cout<<"ssup in 2d"<<endl;
		cout<<"***tess"<<endl; //print statement => denotes the beginning of tesselation field
		cout<<" **format"<<endl; //print statement => denotes the beginning of format field
		cout<<"  3.4"<<endl; //version
		cout<<" **general"<<endl; //print statement => denotes the beginning of general field
		cout<<"  2 standard"<<endl; //2 dim type always standard
		cout<<" **cell"<<endl; //print statement => denotes the beginning of cell field
		cout<<"  "<<n<<endl; //number of cells
		cout<<"  *id"<<endl; //cell identifiers

		cout<<"   ";
		for(int i=1;i<=n;i++){
			cout<<i<<" ";      //print the values of cell identifiers => 1 2 3 4
		}
		cout<<endl;

		cout<<"  *crysym"<<endl; //print statements
		cout<<"   triclinic"<<endl; //print statements

		cout<<"  *seed"<<endl; //print statement => denotes the beginning of seed field
		//I have implemented seeds as the centroids of the four facets
		double ansx[100]={0}; //this will store the x-coordinates of all the centroids
		double ansy[100]={0}; //this will store the y-coordinates of all the centroids
		double ansz[100]={0}; //this will store the z-coordinates of all the centroids
		//cout<<ansz[52]<<"hello";
		//by default the z coordinate is 1 for 2-D

		for(int i=1;i<=nf;i++){ //find the (x, y) values of centroids of facets
			ansy[i] = (node[edge[facet[i-1][2]-1][2]-1][2] + node[edge[facet[i-1][2]-1][1]-1][2])/2; 
			ansx[i] = (node[edge[facet[i-1][1]-1][1]-1][1] + node[edge[facet[i-1][1]-1][2]-1][1])/2;

		}
		for(int i=1;i<=nf;i++){ //printing the values of centroids
			cout<<"   "<<i<<" "<<ansx[i]<<" "<<ansy[i]<<" "<<ansz[i]<<" "<<"0.00"<<endl;
		}

		//cout<<"  *ori"<<endl; //what to print in ori fields ??????????
		cout<<" **vertex"<<endl;//print statement => denotes the beginning of vertex field
		cout<<" "<<nv<<endl; //number of vertices => they are 12 in number for our given problem
		cout<<"   ";
		//printing the (x, y, z) coordinates of all the 12 vertices
		for(int i=0;i<nv;i++){
			cout<<i+1;
			for(int j=1;j<=3;j++){
				if(j==1){
					cout<<" ";
				}
				cout<<node[i][j]<<" ";
			}
			cout<<"0";
			cout<<endl;
			if(i!=nv-1) {cout<<"   ";}
		}
		cout<<" **edge"<<endl; //print statement => denotes the beginning of edge field
		cout<<" "<<ne<<endl; //number of edges ; they are 12 in number for our given problem
		cout<<"   ";
		//printing the endpoits of the edges along with edge_state which is 0 by default
		for(int i=0;i<ne;i++){
			cout<<i+1;
			for(int j=1;j<=2;j++){
				if(j==1){
					cout<<" ";
				}
				cout<<edge[i][j]<<" ";
			}
			cout<<"0";
			cout<<endl;
			if(i!=ne-1) {cout<<"   ";}
		}

		//FACE description
		//**face
			// total_number_of_faces
			// face_id number_of_vertices ver_1
			// ver_2 ... number_of_edges edge_1* edge_2* ...
	  //        		face_eq_d face_eq_a face_eq_b face_eq_c
	  //        		face_state face_point face_point_x face_point_y face_point_z
		// int nc = 3;
		cout<<" **face"<<endl;
		//cout<<"hello there";
		cout<<" "<<nf<<endl;
		for(int i=1;i<=nf;i++){
			nc = facet[i-1].size()-1;
			// cout<<nc<<"hi";
			cout<<"   "<<i<<" "<<nc<<" ";

			//Algorithm to print the edges in CCW and with sign
			vector<int> edgeWithSign;
			if(nc%2==0){
				for(int j=1;j<=nc-1;j=j+2){
					// cout<<"this is edge 1: "<<edge[facet[i-1][j]-1][2];
					// cout<<"this is edge 2: "<<edge[facet[i-1][j+1]-1][1];
					// break;

					if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][1]){ //a2=b1
						edgeWithSign.push_back(facet[i-1][j]);
						edgeWithSign.push_back(facet[i-1][j+1]);
						// cout<<"this is edge 1: "<<facet[i-1][j];
					 //    cout<<"this is edge 2: "<<facet[i-1][j+1];

					}
					else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][2]){ //a1=b2
						edgeWithSign.push_back(-facet[i-1][j]);
						edgeWithSign.push_back(-facet[i-1][j+1]);
					}
					else if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][2]){ //a2=b2
						edgeWithSign.push_back(facet[i-1][j]);
						edgeWithSign.push_back(-facet[i-1][j+1]);
					}
					else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][1]){ //a1=b1
						edgeWithSign.push_back(-facet[i-1][j]);
						edgeWithSign.push_back(facet[i-1][j+1]);
					}
					
				}
			}
			else if (nc%2!=0){
				for(int j=1;j<=nc;j=j+2){
					if(j==nc){
						if(edge[facet[i-1][j-1]-1][2]==edge[facet[i-1][j]-1][1]){ //a2=b1
							edgeWithSign.push_back(facet[i-1][j]);
						}
						else if(edge[facet[i-1][j-1]-1][1]==edge[facet[i-1][j]-1][2]){ //a1=b2
							edgeWithSign.push_back(-facet[i-1][j]);
							
						}
						else if(edge[facet[i-1][j-1]-1][2]==edge[facet[i-1][j]-1][2]){ //a2=b2
							edgeWithSign.push_back(-facet[i-1][j]);
							
						}
						else if(edge[facet[i-1][j-1]-1][1]==edge[facet[i-1][j]-1][1]){ //a1=b1
							edgeWithSign.push_back(facet[i-1][j]);
							
						}
					}
					else{
						if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][1]){ //a2=b1
							edgeWithSign.push_back(facet[i-1][j]);
							edgeWithSign.push_back(facet[i-1][j+1]);

						}
						else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][2]){ //a1=b2
							edgeWithSign.push_back(-facet[i-1][j]);
							edgeWithSign.push_back(-facet[i-1][j+1]);
						}
						else if(edge[facet[i-1][j]-1][2]==edge[facet[i-1][j+1]-1][2]){ //a2=b2
							edgeWithSign.push_back(facet[i-1][j]);
							edgeWithSign.push_back(-facet[i-1][j+1]);
						}
						else if(edge[facet[i-1][j]-1][1]==edge[facet[i-1][j+1]-1][1]){ //a1=b1
							edgeWithSign.push_back(-facet[i-1][j]);
							edgeWithSign.push_back(facet[i-1][j+1]);
						}
					}
				}
			}
			//Algorithm to print edges finished

			//Algorithm to print vertices in CCW
			vector<float> vertrep;
			vector<float> vertnorep;
			for(int p = 0;p<edgeWithSign.size();p++){
				if(edgeWithSign[p]>0){
					vertrep.push_back(edge[edgeWithSign[p]-1][1]);
					vertrep.push_back(edge[edgeWithSign[p]-1][2]);
				}
				else{
					vertrep.push_back(edge[-edgeWithSign[p]-1][2]);
					vertrep.push_back(edge[-edgeWithSign[p]-1][1]);
				}
			}

			for(int itr = 0; itr<vertrep.size()-1;){
				vertnorep.push_back(vertrep[itr]);
				if(vertrep[itr]==vertrep[itr+1]){
					itr = itr+2;
				}
				else{
					itr = itr+1;
				}
			}
			for(int p=0;p<vertnorep.size();p++){
				cout<<vertnorep[p]<<" ";
			}
			cout<<endl;
			cout<<"     "<<nc<<" ";
			
			for(int p =0;p<edgeWithSign.size();p++){
				cout<<edgeWithSign[p]<<" ";
			}
			
			cout<<endl;
			cout<<"     0 0 0 -1"<<endl; //face_eq_c = -1 because normal is z axis
			//assumes that the points lie on z  = 0 plane
			cout<<"     0 -1 0 0 0"<<endl; //face point value is -1 in system generated file so I put the same
			
			edgeWithSign.clear();
			vertrep.clear();
			vertnorep.clear();

		}


		cout<<" **domain"<<endl; //print statement => denotes the beginning of domain field
		cout<<"  *general"<<endl;//print statement => denotes the beginning of general in domain field
		cout<<"   cube"<<endl; //type
		cout<<"  *vertex"<<endl; //domain vertices
		cout<<"   "<<4<<endl;

		vector<float> xvector;
		vector<float> yvector;
		for(int i=0;i<nv;i++){
			xvector.push_back(node[i][1]);
		}
		for(int i=0;i<nv;i++){
			yvector.push_back(node[i][2]);
		}
		int xmax = *max_element(xvector.begin(), xvector.end());
		int xmin = *min_element(xvector.begin(), xvector.end());
		int ymax = *max_element(yvector.begin(), yvector.end());
		int ymin = *min_element(yvector.begin(), yvector.end());

		float tolerance = 0.05;

		cout<<"   "<<1<<" "<<xmin-tolerance<<" "<<ymin-tolerance<<" 0 "<<"ver"<<1<<endl;
		cout<<"     "<<1<<" "<<1<<endl;
		cout<<"   "<<2<<" "<<xmax+tolerance<<" "<<ymin-tolerance<<" 0 "<<"ver"<<2<<endl;
		cout<<"     "<<1<<" "<<1<<endl;
		cout<<"   "<<3<<" "<<xmax+tolerance<<" "<<ymax+tolerance<<" 0 "<<"ver"<<3<<endl;
		cout<<"     "<<1<<" "<<1<<endl;
		cout<<"   "<<4<<" "<<xmin-tolerance<<" "<<ymax+tolerance<<" 0 "<<"ver"<<4<<endl;
		cout<<"     "<<1<<" "<<1<<endl;


		cout<<"  *edge"<<endl; //print statement => denotes the beginning of domain edge field
		cout<<"   "<<4<<endl;

		cout<<"   1 2 2 1"<<endl;
		cout<<"     e1"<<endl;
		cout<<"     0"<<endl;
		
		cout<<"   2 2 3 2"<<endl;
		cout<<"     e2"<<endl;
		cout<<"     0"<<endl;

		cout<<"   3 2 4 3"<<endl;
		cout<<"     e3"<<endl;
		cout<<"     0"<<endl;
	
		cout<<"   4 2 1 4"<<endl;
		cout<<"     e4"<<endl;
		cout<<"     0"<<endl;

		cout<<"***end"<<endl;

	}
	else if(d==3){

		ifstream inputFile0;
	    inputFile0.open("filenames_3d.txt");
	    vector<vector<string> > names;
	    string line0 = "";

	    while(getline(inputFile0, line0)){
		    // int nodeId;
		    string nodefile;
		    string edgefile;
		    string facetfile;
		    string polyhedronfile;
		    vector<string> row0;

		    

		    stringstream inputString(line0);

		    string tempString01;
		    getline(inputString, tempString01, ' ');
		    row0.push_back(tempString01);

		    string tempString02;
		    getline(inputString, tempString02, ' ');
		    row0.push_back(tempString02);

		    string tempString03;
		    getline(inputString, tempString03, ' ');
		    row0.push_back(tempString03);

		    string tempString04;
		    getline(inputString, tempString04, ' ');
		    row0.push_back(tempString04);





		    // tempString = "";
		    // stringstream inputString(line2);
		    // string tempString2;
		    // getline(inputString, tempString2, ',');
		    // xcord = atof(tempString2.c_str());
		    // row.push_back(xcord);

		    // // tempString = "";
		    // // stringstream inputString(line3);
		    // string tempString3;
		    // getline(inputString, tempString3, ',');
		    // ycord = atof(tempString3.c_str());
		    // row.push_back(ycord);

		    // // tempString = "";
		    // // stringstream inputString(line4);
		    // string tempString4;
		    // getline(inputString, tempString4, ',');
		    // zcord = atof(tempString4.c_str());
		    // row.push_back(zcord);

		    names.push_back(row0);

		    line0 = "";
	  	}

		//reading node csv file into a vector of vectors
		ifstream inputFile;
	    inputFile.open(names[0][0]);
	    // cout<bb;
	    ifstream inputFile2;
	    inputFile2.open(names[1][0]);
	    // cout<<"  hi";
	    vector<vector<double> > node;
	    string line1 = "";

	    while(getline(inputFile, line1)){
		    int nodeId;
		    double xcord;
		    double ycord;
		    double zcord;
		    double weight;
		    vector<double> row;

		    

		    stringstream inputString(line1);

		    string tempString1;
		    getline(inputString, tempString1, ',');
		    nodeId = atoi(tempString1.c_str());
		    row.push_back(nodeId);

		    // tempString = "";
		    // stringstream inputString(line2);
		    string tempString2;
		    getline(inputString, tempString2, ',');
		    xcord = atof(tempString2.c_str());
		    row.push_back(xcord);

		    // tempString = "";
		    // stringstream inputString(line3);
		    string tempString3;
		    getline(inputString, tempString3, ',');
		    ycord = atof(tempString3.c_str());
		    row.push_back(ycord);

		    // tempString = "";
		    // stringstream inputString(line4);
		    string tempString4;
		    getline(inputString, tempString4, ',');
		    zcord = atof(tempString4.c_str());
		    row.push_back(zcord);

		    node.push_back(row);

		    line1 = "";
	  	}

	  	// cout<<"i am beginning the edge reading";
	  	// cout<<b<<"hi";

	  	//reading edge csv file into a vector of vectors
	  	
	    vector<vector<int> > edge;
	    string line2 = "";

	    while(getline(inputFile2, line2)){
		    int edgeId;
		    int ecord1;
		    int ecord2;
		    double weight2;
		    vector<int> row2;

		    

		    stringstream inputString(line2);

		    string tempString12;
		    getline(inputString, tempString12, ',');
		    edgeId = atoi(tempString12.c_str());
		    row2.push_back(edgeId);

		    // tempString = "";
		    // stringstream inputString(line2);
		    string tempString22;
		    getline(inputString, tempString22, ',');
		    ecord1 = atoi(tempString22.c_str());
		    row2.push_back(ecord1);

		    // tempString = "";
		    // stringstream inputString(line3);
		    string tempString32;
		    getline(inputString, tempString32, ',');
		    ecord2 = atoi(tempString32.c_str());
		    row2.push_back(ecord2);

		    // tempString = "";
		    // stringstream inputString(line4);
		    string tempString42;
		    getline(inputString, tempString42, ',');
		    weight2 = atoi(tempString42.c_str());
		    row2.push_back(weight2);

		    edge.push_back(row2);

		    line2 = "";
	  	}

	  	

	  	//reading facet csv file into a vector of vectors
	  	ifstream inputFile3;
	    inputFile3.open(names[2][0]);
	    vector<vector<int> > facet;
	    string line3 = "";

	    while(getline(inputFile3, line3)){
		    int facetId;
		    int num_ed;
		    vector<int> row3;

		    stringstream inputString(line3);


		    string tempString13;
		    getline(inputString, tempString13, ',');
		    facetId = atoi(tempString13.c_str());
		    row3.push_back(facetId);

		    string tempString23;
		    getline(inputString, tempString23, ',');
		    num_ed = atoi(tempString23.c_str());
		    // cout<<num_ed<<"||";
		    
		    int u = 1;
		    int e;
		    string tempstring33;

		    while(u<=num_ed){
		    	e = 0;
		    	tempstring33 = "";
		    	getline(inputString, tempstring33, ',');
		    	e = atoi(tempstring33.c_str());
		    	row3.push_back(e);
		    	u++;
		    }


		    facet.push_back(row3);

		    line3 = "";
	  	}

	  	//reading polyhedron csv file into a vector of vectors
	  	ifstream inputFile4;
	    inputFile4.open(names[3][0]);
	    vector<vector<int> > polyhedron;
	    string line4 = "";

	    while(getline(inputFile4, line4)){
		    int polyId;
		    int num_fac;
		    vector<int> row4;

		    stringstream inputString(line4);


		    string tempString14;
		    getline(inputString, tempString14, ',');
		    polyId = atoi(tempString14.c_str());
		    row4.push_back(polyId);

		    string tempString24;
		    getline(inputString, tempString24, ',');
		    num_fac = atoi(tempString24.c_str());
		    // cout<<num_ed<<"||";
		    
		    int v = 1;
		    int f;
		    string tempstring34;

		    while(v<=num_fac){
		    	f = 0;
		    	tempstring34 = "";
		    	getline(inputString, tempstring34, ',');
		    	f = atoi(tempstring34.c_str());
		    	row4.push_back(f);
		    	v++;
		    }


		    polyhedron.push_back(row4);

		    line4 = "";
	  	}



	  	// for (int i = 0; i < polyhedron.size(); i++)
	   //  {
	   //      for (int j = 0; j < polyhedron[i].size(); j++)
	   //      {
	   //          cout << polyhedron[i][j] << " ";
	   //      }   
	   //      cout << endl;
	   //  }

	    int n = polyhedron.size();
	    // cout<<"the number of cells are :"<<n;

	    int nv = node.size();
	    // cout<<"the number of nodes are :"<<nv;

	    //we are always definining domain to be a cube
	    int ndomver = 8;
		int ndomedge = 12;

		int ne = edge.size();
	    // cout<<"the number of edges are :"<<ne;

	    int nf = facet.size();
	    // cout<<"the number of facets are :"<<nf;

	    // // int nc;
	    // // nc = facet[0].size();
	    // // cout<<"row lenght"<<nc<<endl;
	    // cout<<"The node vector is:"<<endl;
	    // for (int i = 0; i < node.size(); i++)
	    // {
	    //     for (int j = 0; j < node[i].size(); j++)
	    //     {
	    //         cout << node[i][j] << " ";
	    //     }   
	    //     cout << endl;
	    // }


	    // cout<<"The edge vector is:"<<endl;
	    // for (int i = 0; i < edge.size(); i++)
	    // {
	    //     for (int j = 0; j < edge[i].size(); j++)
	    //     {
	    //         cout << edge[i][j] << " ";
	    //     }   
	    //     cout << endl;
	    // }

	    // cout<<"The facet vector is:"<<endl;
	    // for (int i = 0; i < facet.size(); i++)
	    // {
	    //     for (int j = 0; j < facet[i].size(); j++)
	    //     {
	    //         cout << facet[i][j] << " ";
	    //     }   
	    //     cout << endl;
	    // }

	    // cout<<"The polyhedron vector is:"<<endl;
	    // for (int i = 0; i < polyhedron.size(); i++)
	    // {
	    //     for (int j = 0; j < polyhedron[i].size(); j++)
	    //     {
	    //         cout << polyhedron[i][j] << " ";
	    //     }   
	    //     cout << endl;
	    // }
		
		freopen("output_3d.tess", "w", stdout); //write into output2.txt
		// cout<<"sssup in 3d";
		cout<<"***tess"<<endl; //print statement => denotes the beginning of tesselation field
		cout<<" **format"<<endl; //print statement => denotes the beginning of format field
		cout<<"  3.4"<<endl; //version
		cout<<" **general"<<endl; //print statement => denotes the beginning of general field
		cout<<"  3 standard"<<endl; //2 dim type always standard
		cout<<" **cell"<<endl; //print statement => denotes the beginning of cell field
		cout<<"  "<<n<<endl; //number of cells

		cout<<"  *crysym"<<endl; //print statements
		cout<<"   triclinic"<<endl; //print statements


		print_seeds(node, edge, facet, polyhedron, nf, n);

		print_vertices(node, edge, facet, polyhedron, nv);

		print_edges(node, edge, facet, polyhedron, ne);

		//For now, my code just finds the equation of plane given three points, it does not
		//care for the outward direction of the normal 
		print_face_description(node, edge, facet, polyhedron, nf);

		print_polyhedron(polyhedron, n);

		cout<<" **domain"<<endl; //print statement => denotes the beginning of domain field
		cout<<"  *general"<<endl;//print statement => denotes the beginning of general in domain field
		cout<<"   cube"<<endl; //type
		

		vector<float> xvector;
		vector<float> yvector;
		vector<float> zvector;
		for(int i=0;i<nv;i++){
			xvector.push_back(node[i][1]);
		}
		for(int i=0;i<nv;i++){
			yvector.push_back(node[i][2]);
		}
		for(int i=0;i<nv;i++){
			zvector.push_back(node[i][3]);
		}
		int xmax = *max_element(xvector.begin(), xvector.end());
		int xmin = *min_element(xvector.begin(), xvector.end());
		int ymax = *max_element(yvector.begin(), yvector.end());
		int ymin = *min_element(yvector.begin(), yvector.end());
		int zmax = *max_element(zvector.begin(), zvector.end());
		int zmin = *min_element(zvector.begin(), zvector.end());


		float tolerance = 0.05;
		print_dom_vertices(xmax, xmin, ymax, ymin, zmax, zmin, tolerance);
		print_dom_edges();
		print_dom_faces(xmax, xmin, ymax, ymin, zmax, zmin, tolerance);

		cout<<"***end"<<endl;


	}
	else{
		cout<<"You have entered an invalid number."<<endl;
		cout<<"Please enter either 2 or 3 according to the type of tesselation you want"<<endl;
	}

	return 0;
}


















