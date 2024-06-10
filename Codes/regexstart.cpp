// #include <iostream>
// #include <regex>
// #include <fstream>
// #include <string>

// int main() {
//     std::regex reg ("[+]?([0-9]*\\.[0-9]+|[0-9, ;])");
//     std::string line, emailfilename;
//     std::cout << "Enter the name of the input file: ";
//     std::cin >> emailfilename;
//     std::ifstream emailfile(emailfilename);
//     std::ofstream resultfile("resultfile.txt");

//     if (emailfile.is_open() && resultfile.is_open()) {
//         while (getline(emailfile, line)) {
//             std::sregex_iterator current(line.begin(), line.end(), reg);
//             std::sregex_iterator last;

//             while (current != last) {
//                 std::smatch match = *current;
//                 resultfile << match.str() << ",";
//                 if(match.str()==";"){
//                     resultfile << "\n";
//                 }
//                 current++;
//             }
//         }
//         std::cout << "Data successfully saved in 'output_file.csv'" << std::endl;
//         emailfile.close();
//         resultfile.close();
//     }
//     else {
//         std::cout << "File not opened." << std::endl;
//     }

//     return 0;
// }
#include <iostream>
#include <regex>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // std::regex reg ("[+]?([0-9]*\\.[0-9]+|[0-9, ;])");
    regex reg ("-?[[0-9.]+(?:e.?[0-9.]+)?");
    regex reg1 ("[0-9.]+");
    string line0, line1, line2, line3, filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    ifstream file0(filename);
    ifstream file1(filename);
    ifstream file2(filename);
    ifstream file3(filename);
    ofstream resultfilenode;
    resultfilenode.open("noder.csv");
    ofstream resultfileedge;
    resultfileedge.open("edger.csv");
    ofstream resultfilefacet;
    resultfilefacet.open("facetr.csv");
    ofstream resultfilepolyhedron;
    resultfilepolyhedron.open("polyr1.csv");
    // std::ofstream resultfileedge("resultfileedge.txt");

    if (file0.is_open() && resultfilenode.is_open()) {
        while (getline(file0, line0)) {
            // regex reg1 ("-?[\d.]+(?:e-?\d+)?");
            if (line0.substr(0,5).compare("Point")) continue;
            sregex_iterator current0(line0.begin(), line0.end(), reg);
            sregex_iterator last0;
            bool first0 = true;
            while (current0 != last0) {
                smatch match0 = *current0;
                if (!first0) resultfilenode << ",";
                first0 = false;
                resultfilenode << match0.str() ;
                // if(match.str()==";"){
                //     resultfile << "\n";
                // }
                current0++;
            }
            resultfilenode << "\n";
        }
        cout << "Data successfully saved in 'output_file.csv'" << std::endl;
        file0.close();
        resultfilenode.close();
    }
    if (file1.is_open() && resultfileedge.is_open()) {
        while (getline(file1, line1)) {
            if (line1.substr(0,5).compare("Line(")) continue;
            // regex reg2 ("[0-9.]+");
            sregex_iterator current1(line1.begin(), line1.end(), reg1);
            sregex_iterator last1;
            bool first1 = true;
            while (current1 != last1) {
                smatch match1 = *current1;
                if (!first1) resultfileedge << ",";
                first1 = false;
                resultfileedge << match1.str() ;
                // if(match.str()==";"){
                //     resultfile << "\n";
                // }
                current1++;
            }
            resultfileedge << "\n";
        }
        cout << "Data successfully saved in 'output_file.csv'" << std::endl;
        file1.close();
        resultfileedge.close();
    }
    if (file2.is_open() && resultfilefacet.is_open()) {
        while (getline(file2, line2)) {
            if (line2.substr(0,10).compare("Line Loop(")) continue;
            sregex_iterator current2(line2.begin(), line2.end(), reg);
            sregex_iterator last2;
            bool first2 = true;
            while (current2 != last2) {
                smatch match2 = *current2;
                if (!first2) resultfilefacet << ",";
                first2 = false;
                resultfilefacet << match2.str() ;
                // if(match.str()==";"){
                //     resultfile << "\n";
                // }
                current2++;
            }
            resultfilefacet << "\n";
        }
        cout << "Data successfully saved in 'output_file.csv'" << std::endl;
        file2.close();
        resultfilefacet.close();
    }
    if (file3.is_open() && resultfilepolyhedron.is_open()) {
        while (getline(file3, line3)) {
            if (line3.substr(0,14).compare("Surface Loop (")) continue;
            sregex_iterator current3(line3.begin(), line3.end(), reg);
            sregex_iterator last3;
            bool first3 = true;
            while (current3 != last3) {
                smatch match3 = *current3;
                if (!first3) resultfilepolyhedron<< ",";
                first3 = false;
                resultfilepolyhedron << match3.str() ;
                // if(match.str()==";"){
                //     resultfile << "\n";
                // }
                current3++;
            }
            resultfilepolyhedron << "\n";
        }
        cout << "Data successfully saved in 'output_file.csv'" << std::endl;
        file3.close();
        resultfilepolyhedron.close();
    }
    else {
        std::cout << "File not opened." << std::endl;
    }

    return 0;
}

