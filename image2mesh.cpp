#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	string imgcontent, line, width, height, depth;
	// prompt user for filename?
	ifstream inimg ("image.pgm");
	ofstream write ("object.off");

	int line_num;

	inimg >> imgcontent;

	line_num = 0;
	while(inimg.good()){
  		while(line_num < 5){
			getline(inimg, line);
			//cout << line_num << endl;
			//cout << line << endl;

			// get width and height
			if(line_num == 2){

			}

			// get depth
			if(line_num == 10) { // depth

			}

			// read image contents

			// cout << line << endl;
			line_num += 1;
  		}
  		break;
	}


  	// output mesh.off

	write << "yo";

	inimg.close();
	write.close();

  	return 0;
}
