/* INFSI351 */
/* TP1 - .pgm to .off */
/* Jonatan Dahl, dahl@enst.fr */
/* 2012-02-20 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* get index */
int getIndex(int x, int y, int width) {
	return width*y+x;
}

int main() {

	/* vars */
	string version, z;
	int x=0, y=0, index=-1, width, height, depth, i; // index -1 to skip an empty row in the beginning of the file.... ?!

	/* filestreams */
	ifstream fin ("image.pgm");
	ofstream fout ("mesh.off");

	/* yank imgparams */
	fin >> version >> width >> height >> depth;

	/* coords */
	int indices[width*height][2];

	/* write header lines */
	fout << "OFF" << endl;
	fout << width*height << " " << (width*height)*2 << " " << "0" << endl;

	/* write 3D coords */
	while(fin.good() && y < height) {
		getline(fin, z);
		if (index > -1) {

			fout << x << " " << y << " " << z << endl;
			indices[index][0] = x;
			indices[index][1] = y;

			x += 1; // create the coords
			if ( x == width ) { // increase y and reset x when x reaches width of image (new row)
				x = 0;
				y += 1;
			}
		}
		index += 1;
	}

	/* create faces */
	for ( i=0; i<height*width; i++) {

		x = indices[i][0];
		y = indices[i][1];

		if ( x < width-1 && y < height-1 ) { // don't exceed borders
			fout << "3 " << getIndex(x, y, width) << " " << getIndex(x, y+1, width) << " " << getIndex(x+1, y, width) << endl;
			fout << "3 " << getIndex(x, y+1, width) << " " << getIndex(x+1, y+1, width) << " " << getIndex(x+1, y, width) << endl;
		}
	}

	fin.close();
	fout.close();

	cout << "-------- done --------" << endl;
  	return 0;
}
