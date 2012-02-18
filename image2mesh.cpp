#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main() {

	string version, z, a;
	int x=0, y=0, index=-1, width, height, depth; // index -1 to skip an empty row in the beginning of the file.... ?!

	ifstream fin ("image.pgm");
	ofstream fout ("mesh.off");

	fin >> version >> width >> height >> depth; // img params

	int indices[width*height];
	int face[4];

	fout << "OFF" << endl;
	fout << width*height << " " << (width*height)/3 << " " << "0" << endl;

	while(fin.good()) {
		getline(fin, z);
		if (index > -1) {

			fout << x << " " << y << " " << z << endl;

			x += 1; // create the coords
			if ( x == width - 1 ) { // increase y when x reaches width of image (new row)
				x = 0;
				y += 1;
			}
		}
		index += 1;
	}

	fin.close();
	fout.close();

	cout << "-------- done --------" << endl;
  	return 0;
}
