//788 and 811
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

vector<vector<string> > filenames3D(){
	ifstream inputFile0;
    inputFile0.open("filenames_3d.txt");
    vector<vector<string> > names;
    string line0 = "";

    while(getline(inputFile0, line0)){
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

	    names.push_back(row0);

	    line0 = "";
  	}
	return names;
}

vector<vector<double> > get_node_vector_3d(vector<vector<string> > names){
	//reading node csv file into a vector of vectors
	ifstream inputFile;
    inputFile.open(names[0][0]);
    ifstream inputFile2;
    inputFile2.open(names[1][0]);
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

	    string tempString2;
	    getline(inputString, tempString2, ',');
	    xcord = stod(tempString2.c_str());
	    row.push_back(xcord);

	    string tempString3;
	    getline(inputString, tempString3, ',');
	    ycord = stod(tempString3.c_str());
	    row.push_back(ycord);

	    string tempString4;
	    getline(inputString, tempString4, ',');
	    zcord = stod(tempString4.c_str());
	    row.push_back(zcord);

	    node.push_back(row);

	    line1 = "";
  	}
	return node;
}

vector<vector<int> > get_edge_vector_3d(vector<vector<string> > names){
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

	    string tempString22;
	    getline(inputString, tempString22, ',');
	    ecord1 = atoi(tempString22.c_str());
	    row2.push_back(ecord1);

	    string tempString32;
	    getline(inputString, tempString32, ',');
	    ecord2 = atoi(tempString32.c_str());
	    row2.push_back(ecord2);

	    string tempString42;
	    getline(inputString, tempString42, ',');
	    weight2 = atoi(tempString42.c_str());
	    row2.push_back(weight2);

	    edge.push_back(row2);

	    line2 = "";
  	}
	return edge;
}

vector<vector<int> > get_facet_vector_3d(vector<vector<string> > names){
	//reading facet csv file into a vector of vectors
  	ifstream inputFile3;
    inputFile3.open(names[2][0]);
    vector<vector<int> > facet;
    string line3 = "";
    int num_ed=0;
	char ch = ',';
    
    while(getline(inputFile3, line3)){

	    int facetId;
	    num_ed=0;
		for(int j=0;j<line3.size();j++){
			if(line3[j]==','){
				num_ed++;	
			}
		}

	    vector<int> row3;

	    stringstream inputString(line3);

	    string tempString13;
	    getline(inputString, tempString13, ',');
	    facetId = atoi(tempString13.c_str());
	    row3.push_back(facetId);
	   
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
	return facet;
}

vector<vector<int> > get_polyhedron_vector_3d(vector<vector<string> > names){
	//reading polyhedron csv file into a vector of vectors
  	ifstream inputFile4;
    inputFile4.open(names[3][0]);
    vector<vector<int> > polyhedron;
    string line4 = "";
    int num_fac=0;
	char ch = ',';


    while(getline(inputFile4, line4)){
	    int polyId;
	    num_fac=0;
		for(int j=0;j<line4.size();j++){
			if(line4[j]==','){
				num_fac++;	
			}
		}

	    vector<int> row4;

	    stringstream inputString(line4);


	    string tempString14;
	    getline(inputString, tempString14, ',');
	    polyId = atoi(tempString14.c_str());
	    row4.push_back(polyId);

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

	return polyhedron;
}


vector<vector <double> > print_seeds(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nf, int n){

	// cout<<"  *seed"<<endl; //print statement => denotes the beginning of seed field
	int bf1;
	int be1;
	vector<double> vxp;
	vector<double> vyp;
	vector<double> vzp;
	double xmaxp;
	double xminp;
	double ymaxp;
	double yminp;
	double zmaxp;
	double zminp;
	vector<vector<double> > seeds;


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
		xminp = *min_element(vxp.begin(), vxp.end());
		ymaxp = *max_element(vyp.begin(), vyp.end());
		yminp = *min_element(vyp.begin(), vyp.end());
		zmaxp = *max_element(vzp.begin(), vzp.end());
		zminp = *min_element(vzp.begin(), vzp.end());

		// cout<<"   "<<i+1<<" "<<(xminp+xmaxp)/2<<" "<<(yminp+ymaxp)/2<<" "<<(zminp+zmaxp)/2<<" 0"<<endl;
		vector<double> seed_row;
		seed_row.push_back(i+1);
		seed_row.push_back((xminp+xmaxp)/2.0);
		seed_row.push_back((yminp+ymaxp)/2.0);
		seed_row.push_back((zminp+zmaxp)/2.0);
		seed_row.push_back(0);

		seeds.push_back(seed_row);

		

		vxp.clear();
		vyp.clear();
		vzp.clear();
	}
	return seeds;
}

void print_vertices(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nv){

	cout<<" **vertex"<<endl;//print statement => denotes the beginning of vertex field
	cout<<" "<<nv<<endl; //number of vertices => they are 12 in number for our given problem
	cout<<"   ";
	for(int i=0;i<nv;i++){
		cout<<i+1;
		for(int j=1;j<=3;j++){
			if(j==1){
				cout<<" ";
			}
			cout<<setprecision(15)<<node[i][j]<<" ";
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

void plane_params(double x1, double y1, double z1, double x2,double y2, double z2, double x3, double y3, double z3){
	vector<double> v1;
	double a1 = x2 - x1;
    double b1 = y2 - y1;
    double c1 = z2 - z1;
    double a2 = x3 - x1;
    double b2 = y3 - y1;
    double c2 = z3 - z1;
    double a = b1 * c2 - b2 * c1;
    double b = a2 * c1 - a1 * c2;
    double c = a1 * b2 - b1 * a2;
    double d = ( a * x1 + b * y1 + c * z1);
    v1.push_back(d);
    v1.push_back(a);
    v1.push_back(b);
    v1.push_back(c);
    double norm = sqrt((a*a)+(b*b)+(c*c));
    for(int i=0;i<v1.size();i++){
    	v1[i] = v1[i]/norm;
    }
    cout<<"    ";
	for(int i=0;i<v1.size();i++){
		cout<<setprecision(15)<<v1[i]<<" ";
	}

	return;
}

void print_face_description(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, vector<vector<int> > polyhedron, int nf){
	cout<<" **face"<<endl;
	int nc;
	cout<<" "<<nf<<endl;
	for(int i=1;i<=nf;i++){
		nc = facet[i-1].size()-1;
		cout<<"   "<<i<<" "<<nc<<" ";

		//Code to print the edges in CCW and with sign
		vector<int> edgeWithSign;
		if(nc%2==0){
			for(int j=1;j<=nc-1;j=j+2){
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
//------//Code to print edges finished//---------------------------------------------------

//------//Code to print vertices in CCW//--------------------------------------------------
		vector<double> vertrep;
		vector<double> vertnorep;
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
		edgeWithSign.clear();
		
//------//Code to print vertices in CCW manner finished//---------------------------
		cout<<endl;


//------//Code to print equation of plane of the face//------------------------------
		// source: https://www.geeksforgeeks.org/program-to-find-equation-of-a-plane-passing-through-3-points/
		int x11;
		int y11;
		int z11;
		int x21;
		int y21;
		int z21;
		int x31;
		int y31;
		int z31;
		double x1;
		double y1;
		double z1;
		double x2;
		double y2;
		double z2;
		double x3;
		double y3;
		double z3;
		for(int r=0;r<vertnorep.size();r++){
			x11 = vertnorep[0]-1;
			y11 = x11;
			z11 = x11;
			x1 = node[x11][1];
			y1 = node[y11][2];
			z1 = node[z11][3];
			// cout<<"This is (x1,y1,z1): ("<<x1<<","<<y1<<","<<z1<<")"<<endl;
			x21 = vertnorep[1]-1;
			y21 = x21;
			z21 = x21;
			x2 = node[x21][1];
			y2 = node[y21][2];
			z2 = node[z21][3];
			// cout<<"This is (x2,y2,z2): ("<<x2<<","<<y2<<","<<z2<<")"<<endl;
			x31 = vertnorep[r+2]-1;
			y31 = x31;
			z31 = x31;
			x3 = node[x31][1];
			y3 = node[y31][2];
			z3 = node[z31][3];
			// cout<<"This is (x3,y3,z3): ("<<x3<<","<<y3<<","<<z3<<")"<<endl;
			
			double v1i = x2 - x1;
		    double v1j = y2 - y1;
		    double v1k = z2 - z1;
		    // cout<<"The first vector is:"<<v1i<<"i_cap, "<<v1j<<"j_cap, "<<v1k<<"k_cap, "<<endl;
		    double v2i = x3 - x1;
		    double v2j = y3 - y1;
		    double v2k = z3 - z1;
		    // cout<<"The Second vector is:"<<v2i<<"i_cap, "<<v2j<<"j_cap, "<<v2k<<"k_cap, "<<endl;
		    double mag_v_i = (v1j*v2k) - (v1k*v2j);
		    double mag_v_j = (v1k*v2i) - (v2k*v1i);
		    double mag_v_k = (v1i*v2j) - (v1j*v2i);
		    // cout<<"Cross vector is:"<<mag_v_i<<"i_cap, "<<mag_v_j<<"j_cap, "<<mag_v_k<<"k_cap, "<<endl;
		    double magnitude = (mag_v_i*mag_v_i)+(mag_v_j*mag_v_j)+(mag_v_k*mag_v_k);
		    // cout<<"mag_v_i^2 = "<<mag_v_i*mag_v_i<<endl;
		    // cout<<"mag_v_j^2 = "<<mag_v_j*mag_v_j<<endl;
		    // cout<<"mag_v_k^2 = "<<mag_v_k*mag_v_k<<endl;
		    // cout<<"Initial magnitude = "<<magnitude<<endl;
			while((magnitude)==0){
				r++;
				x31 = vertnorep[r+2]-1;
				y31 = x31;
				z31 = x31;
				x3 = node[x31][1];
				y3 = node[y31][2];
				z3 = node[z31][3];
				if((x3 == x1 and y3 == y1)  and (z3==z1)){
					cout<<"It is not a face, all the points lie on same line"<<endl;
					// r--;
					x31 = vertnorep[r+2]-1;
					y31 = x31;
					z31 = x31;
					x3 = node[x31][1];
					y3 = node[y31][2];
					z3 = node[z31][3];
					break;
				}
				// cout<<"This is (x3,y3,z3) after update: ("<<x3<<","<<y3<<","<<z3<<")"<<endl;
				v2i = x3 - x1;
				v2j = y3 - y1;
				v2k = z3 - z1;
				mag_v_i = (v1j*v2k) - (v1k*v2j);
				mag_v_j = (v1k*v2i) - (v2k*v1i);
				mag_v_k = (v1i*v2j) - (v1j*v2i);
				magnitude = (mag_v_i*mag_v_i)+(mag_v_j*mag_v_j)+(mag_v_k*mag_v_k);
				// cout<<"Magnitude after updation:"<<magnitude<<endl;
				
				// break;
			}
			break;

		}
		plane_params(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		// bring the parameters in direction cosine form
		
		cout<<endl;

//------//Code to print equation of plane of the face finished//---------------------

		cout<<"     0 0 0 0 0"<<endl; //print line
		vertrep.clear();
		vertnorep.clear();
	}

	return;
} 

void print_polyhedron(vector<vector<int> > polyhedron, int n){
    cout<<" **polyhedron"<<endl<<" "<<n<<endl;
    map<int,int> dict;
    vector<vector<int> > newPoly; 
    
    for (int current =0;current<n;current++)
    {
        vector<int > vect1;
        for (int face=1;face<polyhedron[current].size()+1;face++)
        {
            if (dict[polyhedron[current][face]]==0)
            {
                dict[polyhedron[current][face]]=1;
                vect1.push_back(polyhedron[current][face]);
            }
            else 
            {
                vect1.push_back(-polyhedron[current][face]);
            }
        }
        cout<<"   "<<current+1<<" "<<polyhedron[current].size()-1<<" ";
        for(int i=0;i<vect1.size()-1;i++){
        	cout<<vect1[i]<<" ";

        }cout<<endl;
        vect1.clear();

    }
    
    return ;
}


void print_dom_vertices(int xmax, int xmin, int ymax, int ymin, int zmax, int zmin, double tolerance){
	cout<<"  *vertex"<<endl; //domain vertices
	cout<<"   "<<8<<endl;

	cout<<"   "<<1<<"  "<<setprecision(15)<<xmin-tolerance<<" "<<setprecision(15)<<ymin-tolerance<<" "<<setprecision(15)<<zmin-tolerance<<" ver"<<1<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<2<<"  "<<setprecision(15)<<xmax+tolerance<<" "<<setprecision(15)<<ymin-tolerance<<" "<<setprecision(15)<<zmin-tolerance<<" ver"<<2<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<3<<"  "<<setprecision(15)<<xmax+tolerance<<" "<<setprecision(15)<<ymax+tolerance<<" "<<setprecision(15)<<zmin-tolerance<<" ver"<<3<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<4<<"  "<<setprecision(15)<<xmin-tolerance<<" "<<setprecision(15)<<ymax+tolerance<<" "<<setprecision(15)<<zmin-tolerance<<" ver"<<4<<endl;
	cout<<"     "<<1<<" "<<1<<endl;

	cout<<"   "<<5<<"  "<<setprecision(15)<<xmin-tolerance<<" "<<setprecision(15)<<ymin-tolerance<<" "<<setprecision(15)<<zmin+tolerance<<" ver"<<1<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<6<<"  "<<setprecision(15)<<xmax-tolerance<<" "<<setprecision(15)<<ymin+tolerance<<" "<<setprecision(15)<<zmin+tolerance<<" ver"<<2<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<7<<"  "<<setprecision(15)<<xmax+tolerance<<" "<<setprecision(15)<<ymax+tolerance<<" "<<setprecision(15)<<zmin+tolerance<<" ver"<<3<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<8<<"  "<<setprecision(15)<<xmin+tolerance<<" "<<setprecision(15)<<ymax-tolerance<<" "<<setprecision(15)<<zmin+tolerance<<" ver"<<4<<endl;
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

void print_dom_faces(int xmax, int xmin, int ymax, int ymin, int zmax, int zmin, double tolerance){
	cout<<" *face"<<endl;
	cout<<"   6"<<endl;

	cout<<"   1 4 6 5 8 7"<<endl;
	cout<<"     4 10 6 9 12"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<xmin-tolerance<<" -1 0 0"<<endl;
	cout<<"     f1"<<endl;
	cout<<"     0"<<endl;

	cout<<"   2 4 3 6 7 2"<<endl;
	cout<<"     4 11 12 8 2"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<xmax+tolerance<<" 1 0 0"<<endl;
	cout<<"     f2"<<endl;
	cout<<"     0"<<endl;

	cout<<"   3 4 3 2 1 4"<<endl;
	cout<<"     4 2 1 4 3"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<ymin-tolerance<<" 0 -1 0"<<endl;
	cout<<"     f3"<<endl;
	cout<<"     0"<<endl;

	cout<<"   4 4 4 1 8 5"<<endl;
	cout<<"     4 4 7 6 5"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<ymax+tolerance<<" 0 1 0"<<endl;
	cout<<"     f4"<<endl;
	cout<<"     0"<<endl;

	cout<<"   5 4 2 7 8 1"<<endl;
	cout<<"     4 8 9 7 1"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<zmin-tolerance<<" 0 0 -1"<<endl;
	cout<<"     f5"<<endl;
	cout<<"     0"<<endl;

	cout<<"   6 4 3 4 5 6"<<endl;
	cout<<"     4 3 5 10 11"<<endl;
	cout<<"     plane"<<endl;
	cout<<"     4 "<<setprecision(15)<<zmax+tolerance<<" 0 0 1"<<endl;
	cout<<"     f6"<<endl;
	cout<<"     0"<<endl;

	return;
}

vector<vector <double> > print_seeds_2d(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, int nf, int n){
	
	int be1;
	vector<double> vxp;
	vector<double> vyp;
	vector<double> vzp;
	double xmaxp;
	double xminp;
	double ymaxp;
	double yminp;
	double zmaxp;
	double zminp;
	vector<vector<double> > seeds1;


	for(int i=0;i<nf;i++){
		be1 = facet[i].size()-1;
		for(int k=1;k<=be1;k++){
			for(int m=1;m<=2;m++){
				vxp.push_back(node[edge[facet[i][k]-1][m]-1][1]);
				vyp.push_back(node[edge[facet[i][k]-1][m]-1][2]);
				vzp.push_back(node[edge[facet[i][k]-1][m]-1][3]);
			}
		}
		xmaxp = *max_element(vxp.begin(), vxp.end());
		xminp = *min_element(vxp.begin(), vxp.end());
		ymaxp = *max_element(vyp.begin(), vyp.end());
		yminp = *min_element(vyp.begin(), vyp.end());
		zmaxp = *max_element(vzp.begin(), vzp.end());
		zminp = *min_element(vzp.begin(), vzp.end());




		// cout<<"   "<<i+1<<" "<<(xminp+xmaxp)/2<<" "<<(yminp+ymaxp)/2<<" "<<(zminp+zmaxp)/2<<" 0"<<endl;
		vector<double> seed_row1;
		seed_row1.push_back(i+1);
		seed_row1.push_back((xminp+xmaxp)/2);
		seed_row1.push_back((yminp+ymaxp)/2);
		seed_row1.push_back((zminp+zmaxp)/2);
		seed_row1.push_back(0);

		seeds1.push_back(seed_row1);
		vxp.clear();
		vyp.clear();
		vzp.clear();
	}
	return seeds1;
}

void print_vertices_2d(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, int nv){
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
				cout<<setprecision(15)<<node[i][j]<<" ";
			}
			cout<<"0";
			cout<<endl;
			if(i!=nv-1) {cout<<"   ";}
		}
	return;
}

void print_edges_2d(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, int ne){
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

void print_face_description_2d(vector<vector<double> > node, vector<vector<int> > edge, vector<vector<int> > facet, int nf){
	
	cout<<" **face"<<endl;
	int nc;
	cout<<" "<<nf<<endl;
	for(int i=1;i<=nf;i++){
		nc = facet[i-1].size()-1;
		cout<<"   "<<i<<" "<<nc<<" ";

		//Code to print the edges in CCW and with sign
		vector<int> edgeWithSign;
		if(nc%2==0){
			for(int j=1;j<=nc-1;j=j+2){
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
//------//Code to print edges finished//---------------------------------------------------

//------//Code to print vertices in CCW//--------------------------------------------------
		vector<double> vertrep;
		vector<double> vertnorep;
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
		edgeWithSign.clear();
		
//------//Code to print vertices in CCW manner finished//---------------------------
		cout<<endl;


//------//Code to print equation of plane of the face//------------------------------
		int x11;
		int y11;
		int z11;
		int x21;
		int y21;
		int z21;
		int x31;
		int y31;
		int z31;
		double x1;
		double y1;
		double z1;
		double x2;
		double y2;
		double z2;
		double x3;
		double y3;
		double z3;
		for(int r=0;r<vertnorep.size();r++){
			x11 = vertnorep[0]-1;
			y11 = x11;
			z11 = x11;
			x1 = node[x11][1];
			y1 = node[y11][2];
			z1 = node[z11][3];
			// cout<<"This is (x1,y1,z1): ("<<x1<<","<<y1<<","<<z1<<")"<<endl;
			x21 = vertnorep[1]-1;
			y21 = x21;
			z21 = x21;
			x2 = node[x21][1];
			y2 = node[y21][2];
			z2 = node[z21][3];
			// cout<<"This is (x2,y2,z2): ("<<x2<<","<<y2<<","<<z2<<")"<<endl;
			x31 = vertnorep[r+2]-1;
			y31 = x31;
			z31 = x31;
			x3 = node[x31][1];
			y3 = node[y31][2];
			z3 = node[z31][3];
			// cout<<"This is (x3,y3,z3): ("<<x3<<","<<y3<<","<<z3<<")"<<endl;
			
			double v1i = x2 - x1;
		    double v1j = y2 - y1;
		    double v1k = z2 - z1;
		    // cout<<"The first vector is:"<<v1i<<"i_cap, "<<v1j<<"j_cap, "<<v1k<<"k_cap, "<<endl;
		    double v2i = x3 - x1;
		    double v2j = y3 - y1;
		    double v2k = z3 - z1;
		    // cout<<"The Second vector is:"<<v2i<<"i_cap, "<<v2j<<"j_cap, "<<v2k<<"k_cap, "<<endl;
		    double mag_v_i = (v1j*v2k) - (v1k*v2j);
		    double mag_v_j = (v1k*v2i) - (v2k*v1i);
		    double mag_v_k = (v1i*v2j) - (v1j*v2i);
		    // cout<<"Cross vector is:"<<mag_v_i<<"i_cap, "<<mag_v_j<<"j_cap, "<<mag_v_k<<"k_cap, "<<endl;
		    double magnitude = (mag_v_i*mag_v_i)+(mag_v_j*mag_v_j)+(mag_v_k*mag_v_k);
		    // cout<<"mag_v_i^2 = "<<mag_v_i*mag_v_i<<endl;
		    // cout<<"mag_v_j^2 = "<<mag_v_j*mag_v_j<<endl;
		    // cout<<"mag_v_k^2 = "<<mag_v_k*mag_v_k<<endl;
		    // cout<<"Initial magnitude = "<<magnitude<<endl;
			while((magnitude)==0){
				r++;
				x31 = vertnorep[r+2]-1;
				y31 = x31;
				z31 = x31;
				x3 = node[x31][1];
				y3 = node[y31][2];
				z3 = node[z31][3];
				if((x3 == x1 and y3 == y1)  and (z3==z1)){
					cout<<"It is not a face, all the points lie on a same line"<<endl;
					r--;
					x31 = vertnorep[r+2]-1;
					y31 = x31;
					z31 = x31;
					x3 = node[x31][1];
					y3 = node[y31][2];
					z3 = node[z31][3];
					break;
				}
				// cout<<"This is (x3,y3,z3) after update: ("<<x3<<","<<y3<<","<<z3<<")"<<endl;
				v2i = x3 - x1;
				v2j = y3 - y1;
				v2k = z3 - z1;
				mag_v_i = (v1j*v2k) - (v1k*v2j);
				mag_v_j = (v1k*v2i) - (v2k*v1i);
				mag_v_k = (v1i*v2j) - (v1j*v2i);
				magnitude = (mag_v_i*mag_v_i)+(mag_v_j*mag_v_j)+(mag_v_k*mag_v_k);
				// cout<<"Magnitude after updation:"<<magnitude<<endl;
				
				// break;
			}
			break;

		}
		plane_params(x1, y1, z1, x2, y2, z2, x3, y3, z3);
		// bring the parameters in direction cosine form
		
		cout<<endl;

//------//Code to print equation of plane of the face finished//---------------------

		cout<<"     0 0 0 0 0"<<endl; //print line
		vertrep.clear();
		vertnorep.clear();
	}

	return;
}


void print_dom_vertices_2d(int xmax, int xmin, int ymax, int ymin, int dom_z_coordinate, double tolerance){
	cout<<"  *vertex"<<endl; //domain vertices
	cout<<"   "<<4<<endl;

	cout<<"   "<<1<<" "<<setprecision(15)<<xmin-tolerance<<" "<<setprecision(15)<<ymin-tolerance<<" "<<dom_z_coordinate<<" "<<"ver"<<1<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<2<<" "<<setprecision(15)<<xmax+tolerance<<" "<<setprecision(15)<<ymin-tolerance<<" "<<dom_z_coordinate<<" "<<"ver"<<2<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<3<<" "<<setprecision(15)<<xmax+tolerance<<" "<<setprecision(15)<<ymax+tolerance<<" "<<dom_z_coordinate<<" "<<"ver"<<3<<endl;
	cout<<"     "<<1<<" "<<1<<endl;
	cout<<"   "<<4<<" "<<setprecision(15)<<xmin-tolerance<<" "<<setprecision(15)<<ymax+tolerance<<" "<<dom_z_coordinate<<" "<<"ver"<<4<<endl;
	cout<<"     "<<1<<" "<<1<<endl;

	return;
}

void print_dom_edges_2d(){
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

	return;
}

vector<vector<string> > filenames2D(){

	ifstream inputFile0;
    inputFile0.open("filenames_2d.txt");
    vector<vector<string> > names;
    string line0 = "";

    while(getline(inputFile0, line0)){
	    // int nodeId;
	    string nodefile;
	    string edgefile;
	    string facetfile;
	    // string polyhedronfile;
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

	    names.push_back(row0);

	    line0 = "";
  	}

	return names;
}

vector<vector<double> > get_node_vector_2d(vector<vector<string> > names){
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

	    string tempString2;
	    getline(inputString, tempString2, ',');
	    xcord = stod(tempString2.c_str());
	    row.push_back(xcord);

	    string tempString3;
	    getline(inputString, tempString3, ',');
	    ycord = stod(tempString3.c_str());
	    row.push_back(ycord);

	    string tempString4;
	    getline(inputString, tempString4, ',');
	    zcord = stod(tempString4.c_str());
	    row.push_back(zcord);

	    node.push_back(row);

	    line1 = "";
  	}

	return node;
}

vector<vector<int> > get_edge_vector_2d(vector<vector<string> > names){
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

	    string tempString22;
	    getline(inputString, tempString22, ',');
	    ecord1 = atoi(tempString22.c_str());
	    row2.push_back(ecord1);

	    string tempString32;
	    getline(inputString, tempString32, ',');
	    ecord2 = atoi(tempString32.c_str());
	    row2.push_back(ecord2);

	    string tempString42;
	    getline(inputString, tempString42, ',');
	    weight2 = atoi(tempString42.c_str());
	    row2.push_back(weight2);

	    edge.push_back(row2);

	    line2 = "";
  	}


	return edge;
}

vector<vector<int> > get_facet_vector_2d(vector<vector<string> > names){
	//reading facet csv file into a vector of vectors
  	ifstream inputFile3;
    inputFile3.open(names[2][0]);
    vector<vector<int> > facet;
    string line3 = "";
    int num_ed=0;
	char ch = ',';

    while(getline(inputFile3, line3)){
	    int facetId;
	    num_ed=0;
		for(int j=0;j<line3.size();j++){
			if(line3[j]==','){
				num_ed++;	
			}
		}

	    vector<int> row3;

	    stringstream inputString(line3);

	    string tempString13;
	    getline(inputString, tempString13, ',');
	    facetId = atoi(tempString13.c_str());
	    row3.push_back(facetId);

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
	return facet;
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

	  	vector<vector<string> > names = filenames2D();
	    vector<vector<double> > node = get_node_vector_2d(names);
	    vector<vector<int> > edge = get_edge_vector_2d(names);
	    vector<vector<int> > facet = get_facet_vector_2d(names);

	    int n = facet.size();
	    int nv = node.size();
	    int ne = edge.size();
	    int nf = facet.size();

	    //we are always definining domain to be a square
	    int ndomver = 4;
		int ndomedge = 4;

		freopen("output_2d.tess", "w", stdout); //write into output_2d.tess

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
			cout<<i<<" ";      //print the values of cell identifiers => 1 2 3 4 ....
		}
		cout<<endl;

		cout<<"  *crysym"<<endl; //print statements
		cout<<"   triclinic"<<endl; //print statements
		

		vector<vector <double> > seeds = print_seeds_2d(node, edge, facet, nf, n);
		cout<<"  *seed"<<endl;
		for(int p=0;p<seeds.size();p++){
			cout<<"   ";
			for(int q=0;q<seeds[p].size();q++){
				cout<<setprecision(15)<<seeds[p][q]<<" ";
			}
			cout<<endl;
		}

		//We are not printing the Ori field as of now

		print_vertices_2d(node, edge, facet, nv);

		print_edges_2d(node, edge, facet, ne);

		print_face_description_2d(node, edge, facet, nf);

		cout<<" **domain"<<endl; //print statement => denotes the beginning of domain field
		cout<<"  *general"<<endl;//print statement => denotes the beginning of general in domain field
		cout<<"   cube"<<endl; //type

		vector<double> xvector;
		vector<double> yvector;
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
		int dom_z_coordinate = node[0][3];

		double tolerance = 0.05;

		print_dom_vertices_2d(xmax, xmin, ymax, ymin, dom_z_coordinate, tolerance);
		print_dom_edges_2d();

		cout<<"***end"<<endl;

	}

	else if(d==3){

		vector<vector<string> > names = filenames3D();
	    vector<vector<double> > node = get_node_vector_3d(names);
	    vector<vector<int> > edge = get_edge_vector_3d(names);
	    vector<vector<int> > facet = get_facet_vector_3d(names);
	    vector<vector<int> > polyhedron = get_polyhedron_vector_3d(names);

	    int n = polyhedron.size();

	    int nv = node.size();

		int ne = edge.size();
	    
		int nf = facet.size();

	    //we are always definining domain to be a cube
	    int ndomver = 8;
		int ndomedge = 12;

	    
		freopen("output_3d.tess", "w", stdout); //write into output_3d.tess

		cout<<"***tess"<<endl; //print statement => denotes the beginning of tesselation field
		cout<<" **format"<<endl; //print statement => denotes the beginning of format field
		cout<<"  3.4"<<endl; //version
		cout<<" **general"<<endl; //print statement => denotes the beginning of general field
		cout<<"  3 standard"<<endl; //3 dim type always standard
		cout<<" **cell"<<endl; //print statement => denotes the beginning of cell field
		cout<<"  "<<n<<endl; //number of cells
		cout<<"  *id"<<endl; //cell identifiers

		cout<<"   ";
		for(int i=1;i<=n;i++){
			cout<<i<<" ";      //print the values of cell identifiers => 1 2 3 4 ....
		}
		cout<<endl;

		cout<<"  *crysym"<<endl; //print statements
		cout<<"   triclinic"<<endl; //print statements


		vector<vector <double> > seeds = print_seeds(node, edge, facet, polyhedron, nf, n);
		cout<<"  *seed"<<endl;
		for(int p=0;p<seeds.size();p++){
			cout<<"   ";
			for(int q=0;q<seeds[p].size();q++){
				cout<<setprecision(15)<<seeds[p][q]<<" ";
			}
			cout<<endl;
		}


		print_vertices(node, edge, facet, polyhedron, nv);

		print_edges(node, edge, facet, polyhedron, ne);

		//Our code finds the equation of plane given three points
		print_face_description(node, edge, facet, polyhedron, nf);


		print_polyhedron(polyhedron, n);

		cout<<" **domain"<<endl; //print statement => denotes the beginning of domain field
		cout<<"  *general"<<endl;//print statement => denotes the beginning of general in domain field
		cout<<"   cube"<<endl; //type
		

		vector<double> xvector;
		vector<double> yvector;
		vector<double> zvector;
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


		double tolerance = 0.05;
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



