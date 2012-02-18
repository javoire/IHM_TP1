#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/* get index */
int getIndex(int x, int y, int width) {
	return width*y+x;
}

int main() {

	/* vars */
	string version, z_string, line;
	int index=-1, width, height, depth, i; // index -1 to skip an empty row in the beginning of the file.... ?!
	float x=0, y=0, z;

	/* filestreams */
	ifstream fin ("image.pgm");
	ofstream fout ("mesh.off");

	/* yank imgparams */
	fin >> version >> width >> height >> depth;

	/* indexlist + coords */
	int indices[width*height][2];

	/* write header lines */
	fout << "OFF" << endl;
	fout << width*height << " " << (width*height)/3 << " " << "0" << endl;

	/* write 3D coords */
	while(fin.good() && y < height) {
		getline(fin, line);
		if (index > -1) {

			istringstream z_string(line);
			z_string >> z;
			fout << setprecision (10) << fixed << x << " " << y << " " << z << endl;
			indices[index][0] = x;
			indices[index][1] = y;

			x += 1; // create the coords
			if ( x == width ) { // increase y when x reaches width of image (new row)
				x = 0;
				y += 1;
			}
		}
		index += 1;
	}

	/* write face-relations */
	for ( i=0; i<height*width; i++) {

		x = indices[i][0];
		y = indices[i][1];

		if ( x < width-1 && y < height-1 ) { // don't exceed borders
			fout << "3 " << getIndex(x, y, width) << " " << getIndex(x, y+1, width) << " " << getIndex(x+1, y, width) << endl;
			fout << "3 " << getIndex(x, y+1, width) << " " << getIndex(x+1, y+1, width) << " " << getIndex(x+1, y, width) << endl;
		}
	}

	cout << sizeof(indices);

	fin.close();
	fout.close();

	cout << "-------- done --------" << endl;
  	return 0;
}
