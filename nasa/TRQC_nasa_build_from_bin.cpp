
#include "TempRaster_QuadComp.hpp"

using namespace std;
using namespace sdsl;

int main(int argc, char const *argv[]){
	if(argc < 4){
		cout << "Error! Faltan argumentos." << endl;
		cout << argv[0] << " <inputFile> <d_cuadrante> <outputFile>" << endl;
		return 0;
	}
	// Leyendo datos desde el archivo de entrada
	string ifilename(argv[1]);
	ifstream infile(ifilename, ofstream::binary);
	if(infile.fail()){
		cout << "Error! Lectura de " << argv[1] << " fallida." << endl;
		return -1;
	}
	int dcuad = stoi(argv[2]);
	int rows, cols, lenTempSerie;
	// Cargando datos
	infile.read((char *)&rows, sizeof(int));
	infile.read((char *)&cols, sizeof(int));
	infile.read((char *)&lenTempSerie, sizeof(int));

	cout << "File: " << argv[1] << endl;
	cout << "Filas: " << rows << " - Cols: " << cols << " - Muestras: " << lenTempSerie << endl;
	cout << "Total celdas del raster: " << rows * cols << endl;

	vector<vector<vector<int>>> temporalSeries(rows, vector<vector<int>>(cols, vector<int>(lenTempSerie)));
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			for(int k=0; k<lenTempSerie; k++){
				infile.read((char *)&temporalSeries[i][j][k], sizeof(int));
			}
		}
	}
	TempRasterQuadComp nqc(temporalSeries, dcuad);

	string ofilename(argv[3]);
	nqc.save(ofilename);

	cout << "FIN" << endl;

	return 0;
}
