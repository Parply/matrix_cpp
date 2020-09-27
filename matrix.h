#include <cstddef>
#include <vector>
using namespace std;


template<typename T>
class matrix{
	public:
		vector<vector<T>> data;
		size_t columns,rows;
		matrix(size_t rows,size_t cols);
		matrix(vector<vector<T>> &idata);
		void transpose();
		T at(size_t i,size_t j);
		vector<size_t> shape();
		size_t size();
		vector<T> operator[](size_t idx){ return data[idx];}


};
template<typename T>
matrix<T>::matrix(size_t rows,size_t cols)
{
	
	this->data=vector<T>(rows,vector<T>(cols));
	this->columns=cols;
	this->rows=rows;
}

template<typename T>
matrix<T>::matrix(vector<vector<T>> &idata)
{
	this->data = idata;
	this->rows = idata.size();
	this->columns = idata.at(0).size();
}

template<typename T>
void matrix<T>::transpose()
{

    vector<vector<T>> trans_vec(this->columns, vector<T>(this->rows));
    #pragma omp parallel for schedule(static)
    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->columns; j++)
        {
            trans_vec.at(j).at(i)=this->data.at(i).at(j);
        }
    }
	this->data=trans_vec;
	this->rows=this->data.size();
	this->columns = this->data.at(0).size();
}

template<typename T>
T matrix<T>::at(size_t i, size_t j){
	if ((i>=this->rows)|(j>=this->columns)){
		throw "Index out of range";
	}
	return this->data[i][j];
}

template<typename T>
vector<size_t> matrix<T>::shape(){
	vector<size_t> out;
	out.push_back(this->rows);
	out.push_back(this->columns);
	return out;
}
template<typename T>
size_t matrix<T>::size(){
	return this->rows*this->columns;
}
