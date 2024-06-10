//Do not forget to build the cpp code before running
//facet csv has number of edges but facet vector does not
#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<utility>
using namespace std;

//-----INPUT----------//


//set of edges
//set of vertices
//set of faces (only bounding edges)

// int n = 4;
// double node[9][4] = {{1, 0, 0, 0},
// 				{2, 0.5, 0, 0},
// 				{3, 1, 0, 0},
// 				{4, 1, 0.5, 0}, 
// 				{5, 1, 1, 0}, 
// 				{6, 0.5, 1, 0}, 
// 				{7, 0, 1, 0}, 
// 				{8, 0, 0.5, 0}, 
// 				{9, 0.5, 0.5, 0}};

// int edge[12][3] = {{1, 1, 2},
// 				{2, 2, 3},
// 				{3, 3, 4},
// 				{4, 4, 5}, 
// 				{5, 5, 6}, 
// 				{6, 6, 7}, 
// 				{7, 7, 8}, 
// 				{8, 8, 1}, 
// 				{9, 4, 9}, 
// 				{10, 9, 8}, 
// 				{11, 6, 9}, 
// 				{12, 9, 2}};

// int facet[4][5] = {{1, 10, 8, 1, 12},
// 					{2, 9, 12, 2, 3},
// 					{3, 5, 11, 9, 4},
// 					{4, 6, 7, 10, 11}};


// // double domver[4][4] = {{1, 0, 0, 0}, //get this
// // 						{2, 1, 0, 0},
// // 						{3, 1, 1, 0},
// // 						{4, 0, 1, 0}};


// // int domedge[4][3] = {{1, 1, 2}, //get this from 
// // 					{2, 2, 3}, 
// // 					{3, 3, 4}, 
// // 					{4, 4, 1}};
// int nv = 9;
// int ndomver = 4;
// int ndomedge= 4;
// int ne =12;
// int nf = 4;
// int nc = 5-1;

// int n = 3;
// double node[8][4] = {{1, 0, 0, 0},
// 				{2, 1, 0, 0},
// 				{3, 2, 0, 0},
// 				{4, 2, 1, 0}, 
// 				{5, 1, 1, 0}, 
// 				{6, 1, 2, 0}, 
// 				{7, 0, 2, 0}, 
// 				{8, 0, 1, 0}};

// int edge[10][3] = {{1, 1, 2},
// 				{2, 2, 3},
// 				{3, 3, 4},
// 				{4, 4, 5}, 
// 				{5, 5, 6}, 
// 				{6, 6, 7}, 
// 				{7, 7, 8}, 
// 				{8, 8, 1}, 
// 				{9, 2, 5}, 
// 				{10, 8, 5}};

// int facet[3][5] = {{1, 10, 8, 1, 9},
// 					{2, 4, 9, 2, 3},
// 					{3, 6, 7, 10, 5}};


// int nv = 8;
// int ndomver = 4;
// int ndomedge= 4;
// int ne =10;
// int nf = 3;
// int nc = 5-1;

// int n = 8;
// double node[16][4] = {{1, 0, 0, 0},
// 						{2, 0.3, 0, 0},
// 						{3, 0.6, 0, 0},
// 						{4, 1, 0, 0}, 
// 						{5, 1, 0.3, 0}, 
// 						{6, 0.6, 0.3, 0}, 
// 						{7, 0.3, 0.3, 0}, 
// 						{8, 0, 0.3, 0},
// 						{9, 1, 0.6, 0},
// 						{10, 0.6, 0.6, 0},
// 						{11, 0.3, 0.6, 0},
// 						{12, 0, 0.6, 0}, 
// 						{13, 1, 1, 0}, 
// 						{14, 0.6, 1, 0}, 
// 						{15, 0.3, 1, 0}, 
// 						{16, 0, 1, 0}};

// int edge[24][3] = {{1, 1, 2},
// 				{2, 2, 3},
// 				{3, 3, 4},
// 				{4, 4, 5}, 
// 				{5, 5, 9}, 
// 				{6, 9, 13}, 
// 				{7, 13, 14}, 
// 				{8, 14, 15},
// 				{9, 15, 16},
// 				{10, 16, 12},
// 				{11, 12, 8},
// 				{12, 8, 1}, 
// 				{13, 2, 7}, 
// 				{14, 7, 8}, 
// 				{15, 7, 11}, 
// 				{16, 11, 12},
// 				{17, 11, 15},
// 				{18, 10, 14},
// 				{19, 11, 10},
// 				{20, 10, 6}, 
// 				{21, 7, 6}, 
// 				{22, 3, 6}, 
// 				{23, 6, 5}, 
// 				{24, 9, 10}};

// int facet[8][5] = {{1, 14, 12, 1, 13},
// 					{2, 21, 13, 2, 22},
// 					{3, 23, 22, 3, 4},
// 					{4, 24, 20, 23, 5},
// 					{5, 7, 18, 24, 6},
// 					{6, 8, 17, 19, 18},
// 					{7, 9, 10, 16, 17},
// 					{8, 16, 11, 14, 15}};


// int nv = 16;
// int ndomver = 4;
// int ndomedge= 4;
// int ne = 24;
// int nf = 8;
// int nc = 5-1;


// int n = 2;
// vector<vector<double> > node;
// {{1, 1, 1, 0},
// 				{2, 2, 0, 0},
// 				{3, 3, 1, 0},
// 				{4, 2, 2, 0}};
				
// int edge[5][3] = {{1, 2, 1},
// 				{2, 1, 4},
// 				{3, 4, 3},
// 				{4, 3, 2}, 
// 				{5, 4, 2}};

// int facet[2][4] = {{1, 2, 1, 5},
// 					{2, 3, 5, 4}};


// int nv = 4;

// int ne = 5;
// int nf = 2;
// int nc = 4-1;

// int n = 3;
// double node[12][4] = {{1, 0, 0, 0},
// 				{2, 1, 0, 0},
// 				{3, 2, 0, 0},
// 				{4, 2, 1, 0}, 
// 				{5, 1, 1, 0}, 
// 				{6, 1, 2, 0}, 
// 				{7, 0, 2, 0}, 
// 				{8, 0, 1, 0}, 
// 				{9, 1.2, 0.2, 0}, 
// 				{10, 1.6, 0.2, 0}, 
// 				{11, 1.6, 0.6, 0}, 
// 				{12, 1.2, 0.6, 0}};


// int edge[14][3] = {{1, 1, 2},
// 				{2, 2, 3},
// 				{3, 3, 4},
// 				{4, 4, 5}, 
// 				{5, 5, 6}, 
// 				{6, 6, 7}, 
// 				{7, 7, 8}, 
// 				{8, 8, 1}, 
// 				{9, 2, 5}, 
// 				{10, 8, 5}, 
// 				{11, 9, 10}, 
// 				{12, 10, 11}, 
// 				{13, 11, 12}, 
// 				{14, 12, 9}};

// int facet[4][5] = {{1, 10, 8, 1, 9},
// 					{2, 4, 9, 2, 3},
// 					{3, 6, 7, 10, 5},
// 					{4, 11, 12, 13, 14}};



// int nv = 12;
// int ndomver = 4;
// int ndomedge= 4;
// int ne =14;
// int nf = 4;
// int nc = 5-1;
//--INPUT Values end--//

int main(int argc, char const *argv[])
{
	
	//reading node csv file into a vector of vectors
	ifstream inputFile;
    inputFile.open("node2.csv");
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
    inputFile2.open("edge2.csv");
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
    inputFile3.open("poly2.csv");
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


        //Code is fine below this
		
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

	// vector<int> tessdomver;
	// fill(tessdomver.begin(), tessdomver.end(), 0);

	// for(int i=0;i<nv;i++){
	// 	if(node[i][1]==xmin and node[i][2]==ymin){
	// 		tessdomver.push_back(node[i][0]);
	// 	}
	// 	// }
	// }
	// for(int i=0;i<nv;i++){
	// 	if(node[i][1]==xmax and node[i][2]==ymin){
	// 		tessdomver.push_back(node[i][0]);
	// 	}
	// }
	// for(int i=0;i<nv;i++){
	// 	if(node[i][1]==xmax and node[i][2]==ymax){
	// 		tessdomver.push_back(node[i][0]);
	// 	}
	// }
	// for(int i=0;i<nv;i++){
	// 	if(node[i][1]==xmin and node[i][2]==ymax){
	// 		tessdomver.push_back(node[i][0]);
	// 	}
	// }

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

/////////////////////////////////////////////
// 	vector<int> y0vers;
// 	for(int i=0;i<nv;i++){
// 		if(node[i][2] == ymin){
// 			y0vers.push_back(node[i][0]);
// 		}
// 	}

// 	vector<float> xcordy0vers;
// 	for(int i=0;i<y0vers.size();i++){
// 		xcordy0vers.push_back(node[y0vers[i]-1][1]);
// 	}

// 	vector< pair <float,int> > vy0;
// 	for(int i=0;i<y0vers.size();i++){
// 		vy0.push_back(make_pair(xcordy0vers[i], y0vers[i]));
// 	} 
// 	sort(vy0.begin(), vy0.end());

// 	for(int i=0;i<y0vers.size();i++){
// 		y0vers[i] = vy0[i].second;
// 	}
// 	// for(int i=0;i<y0vers.size();i++){
// 	// 	cout<<"hey"<<y0vers[i];
// 	// }
// 	//int tempsize1 = y0vers.size();
	
// 	vector<int> celldomedgey0;

// 	for(int i=0;i<y0vers.size()-1;i++){
// 		for(int j=0;j<ne;j++){
// 			// cout<<"hello";
// 			if((edge[j][1] == y0vers[i]) and (edge[j][2] == y0vers[i+1])){
// 				// cout<<"yes"<<i<<"yes ";
// 				// cout<<edge[j][0];
// 				celldomedgey0.push_back(edge[j][0]);
// 			}
// 		}
// 	}
// /////////////////////////////////////////////

// /////////////////////////////////////////////
// 	vector<int> x1vers;
// 	for(int i=0;i<nv;i++){ 
// 		if(node[i][1] == xmax){
// 			x1vers.push_back(node[i][0]);
// 		}
// 	}

// 	vector<float> ycordx1vers;
// 	for(int i=0;i<x1vers.size();i++){
// 		ycordx1vers.push_back(node[x1vers[i]-1][2]);
// 	}

// 	vector< pair <float,int> > vx1;
// 	for(int i=0;i<x1vers.size();i++){
// 		vx1.push_back(make_pair(ycordx1vers[i], x1vers[i]));
// 	} 
// 	sort(vx1.begin(), vx1.end());

// 	for(int i=0;i<x1vers.size();i++){
// 		x1vers[i] = vx1[i].second;
// 	}
// 	// for(int i=0;i<y0vers.size();i++){
// 	// 	cout<<"hey"<<y0vers[i];
// 	// }
// 	//int tempsize1 = y0vers.size();
	
// 	vector<int> celldomedgex1;

// 	for(int i=0;i<x1vers.size()-1;i++){
// 		for(int j=0;j<ne;j++){
// 			// cout<<"hello";
// 			if((edge[j][1] == x1vers[i]) and (edge[j][2] == x1vers[i+1]) or (edge[j][1] == x1vers[i+1]) and (edge[j][2] == x1vers[i])){
// 				// cout<<"yes"<<i<<"yes ";
// 				// cout<<edge[j][0];
// 				celldomedgex1.push_back(edge[j][0]);
// 			}
// 		}
// 	}

// 	// for(int i = 0;i<celldomedgex1.size();i++){
// 	// 	cout<<"hey"<<celldomedgex1[i];
// 	// }
// //////////////////////////////////////////////

// /////////////////////////////////////////////
// 	vector<int> y1vers;
// 	for(int i=0;i<nv;i++){ 
// 		if(node[i][2] == ymax){
// 			y1vers.push_back(node[i][0]);
// 		}
// 	}

// 	vector<float> xcordy1vers;
// 	for(int i=0;i<y1vers.size();i++){
// 		xcordy1vers.push_back(node[y1vers[i]-1][1]);
// 	}

// 	vector< pair <float,int> > vy1;
// 	for(int i=0;i<y1vers.size();i++){
// 		vy1.push_back(make_pair(xcordy1vers[i], y1vers[i]));
// 	} 
// 	sort(vy1.rbegin(), vy1.rend());

// 	for(int i=0;i<y1vers.size();i++){
// 		y1vers[i] = vy1[i].second;
// 	}
// 	// for(int i=0;i<y0vers.size();i++){
// 	// 	cout<<"hey"<<y0vers[i];
// 	// }
// 	//int tempsize1 = y0vers.size();
	
// 	vector<int> celldomedgey1;

// 	for(int i=0;i<y1vers.size()-1;i++){
// 		for(int j=0;j<ne;j++){
// 			// cout<<"hello";
// 			if((edge[j][1] == y1vers[i]) and (edge[j][2] == y1vers[i+1]) or (edge[j][1] == y1vers[i+1]) and (edge[j][2] == y1vers[i])){
// 				// cout<<"yes"<<i<<"yes ";
// 				// cout<<edge[j][0];
// 				celldomedgey1.push_back(edge[j][0]);
// 			}
// 		}
// 	}

// 	// for(int i = 0;i<celldomedgex1.size();i++){
// 	// 	cout<<"hey"<<celldomedgey1[i];
// 	// }
// //////////////////////////////////////////////////////////////


// /////////////////////////////////////////////
// 	vector<int> x0vers;
// 	for(int i=0;i<nv;i++){
// 		if(node[i][1] == xmin){
// 			x0vers.push_back(node[i][0]);
// 		}
// 	}

// 	vector<float> ycordx0vers;
// 	for(int i=0;i<x0vers.size();i++){
// 		ycordx0vers.push_back(node[x0vers[i]-1][2]);
// 	}

// 	vector< pair <float,int> > vx0;
// 	for(int i=0;i<x0vers.size();i++){
// 		vx0.push_back(make_pair(ycordx0vers[i], x0vers[i]));
// 	} 
// 	sort(vx0.rbegin(), vx0.rend());

// 	for(int i=0;i<x0vers.size();i++){
// 		x0vers[i] = vx0[i].second;
// 	}
// 	// for(int i=0;i<y0vers.size();i++){
// 	// 	cout<<"hey"<<y0vers[i];
// 	// }
// 	//int tempsize1 = y0vers.size();
	
// 	vector<int> celldomedgex0;

// 	for(int i=0;i<x0vers.size()-1;i++){
// 		for(int j=0;j<ne;j++){
// 			// cout<<"hello";
// 			if((edge[j][1] == x0vers[i]) and (edge[j][2] == x0vers[i+1]) or (edge[j][1] == x0vers[i+1]) and (edge[j][2] == x0vers[i])){
// 				// cout<<"yes"<<i<<"yes ";
// 				// cout<<edge[j][0];
// 				celldomedgex0.push_back(edge[j][0]);
// 			}
// 		}
// 	}

	// for(int i = 0;i<celldomedgex0.size();i++){
	// 	cout<<"hey"<<celldomedgex0[i];
	// }
//////////////////////////////////////////////////////////////
	cout<<"   1 2 2 1"<<endl;
	cout<<"     e1"<<endl;
	cout<<"     0"<<endl;
	// cout<<"     "<<celldomedgey0.size()<<" ";
	// for(int i = 0;i<celldomedgey0.size();i++){
	// 	cout<<celldomedgey0[i]<<" ";
	// }
	// cout<<endl;

	cout<<"   2 2 3 2"<<endl;
	cout<<"     e2"<<endl;
	cout<<"     0"<<endl;
	// cout<<"     "<<celldomedgex1.size()<<" ";
	// for(int i = 0;i<celldomedgex1.size();i++){
	// 	cout<<celldomedgex1[i]<<" ";
	// }cout<<endl;

	cout<<"   3 2 4 3"<<endl;
	cout<<"     e3"<<endl;
	cout<<"     0"<<endl;
	// cout<<"     "<<celldomedgey1.size()<<" ";
	// for(int i = 0;i<celldomedgey1.size();i++){
	// 	cout<<celldomedgey1[i]<<" ";
	// }cout<<endl;

	cout<<"   4 2 1 4"<<endl;
	cout<<"     e4"<<endl;
	cout<<"     0"<<endl;
	// cout<<"     "<<celldomedgex0.size()<<" ";
	// for(int i = 0;i<celldomedgex0.size();i++){
	// 	cout<<celldomedgex0[i]<<" ";
	// }cout<<endl;











/////////////////////////////////////////////////////////
	// for(int i = 0;i<celldomedgey0.size();i++){
	// 	cout<<"hey"<<celldomedgey0[i];
	// }

	// for(int i=0; i<y0vers.size();i++){
	// 	cout<<y0vers[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0; i<y0vers.size();i++){
	// 	cout<<xcordy0vers[i]<<" ";
	// }
	//cout<<"hello print pair "<<vy0[1].first<<" "<<vy0[1].second<<endl;
	// sort(xcordy0vers.begin(), xcordy0vers.end());

	// for(int i=0;i<xcordy0vers.size();i++){
	// 	for(int j=0;j<y0vers.size();j++){
	// 		if(y0vers[j]==)
	// 	}
	// }


	// //printing the bounding edges of the domain using the domedge 2D array
	// for(int i = 0;i<ndomedge;i++){
		
	// 	if(i!=0){
	// 		cout<<"   "<<i+1<<" "<<"2"<<" ";
	// 	}
	// 	if(i==0){
	// 	cout<<i+1<<" "<<"2"<<" ";
	// 	}
	// 	for(int j=1;j<=2;j++){
	// 		cout<<domedge[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// 	cout<<"     edge"<<i+1<<endl<<"     2 "<<ansarr[i]<<" ";

	// 	if(i!= ndomedge-1){cout<<ansarr[i+1]<<endl;}
	// 	else{cout<<ansarr[0]<<endl;}
	// }
	// cout<<"hello";
	cout<<"***end"<<endl;
	
	return 0;
}