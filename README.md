# Tessellation of Micro-structurally Aware Domains using Neper

This repository contains my work completed for an independent research project under the supervision of Prof. Ravi Sastri Ayyagari at the Indian Institute of Technology Gandhinagar, Department of Mechanical Engineering.

### Project Overview
The primary objective of this project was to develop C++ code to generate tessellation files (for both 2-D and 3-D tessellations) using the available grain information to accurately represent microstructurally aware domains.

### Key Contributions
- **Developed a C++ Codebase:** Authored a comprehensive end-to-end C++ code to automate the generation of tessellation files based on available grain information, capable of handling both 2-D and 3-D configurations.
- **Algorithm Examination and Execution:** Studied the core algorithms of Neper and implemented a technique named 'mapping' to tessellate both convex and non-convex domains efficiently.
- **Enhanced Functionality of Neper:** Ensured that the generated tessellations were seamlessly parsed through Neper, thus enhancing its meshing capabilities and visualization features.


To check the working of the code, please follow the instructions given in the [documentation](https://github.com/someshps/Tessellations/blob/main/Documentation_sub.pdf). 

### Repository Details
- **[C++ Code for Tessellation Generation](https://github.com/someshps/Tessellations/tree/main/Codes)**
- **[Documentation](https://github.com/someshps/Tessellations/blob/main/Documentation_sub.pdf)**
- **[CSV_DataFiles:](https://github.com/someshps/Tessellations/tree/main/CSV_DataFiles)** This includes files which contain the grain information in form of csv files. 
- **[GeneratedTessFiles:](https://github.com/someshps/Tessellations/tree/main/GeneratedTessFiles)** Contains all the tessellation files generated from our code. A similar folder is for the geo files which can be converted from tess. We can also read geo files to get grain information and then further use it to generate tessellation files. 
- **[Gen_Imges_UsingNeperV:](https://github.com/someshps/Tessellations/tree/main/Gen_Imges_UsingNeperV)** This contains the images generated by parsing our tessellation files through Neper's visualisation tool. 
