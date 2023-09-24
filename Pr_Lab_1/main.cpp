#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Delta
{
private:
    vector <string> _Massiv;
    int _SizeMas;
    int _LenEl;
public:
    string Return_Element(int _index)
    {
        return _Massiv[_index];
    }
    int GetSizeMas()
    {
      return _SizeMas;
    };
    void MassivAdd()
    {
        string _boofer;
        for (int i =0; i < _SizeMas; i++){
            cin >> _boofer;
            if(_boofer.length() > _LenEl){
                _boofer.erase(_LenEl, _boofer.length() - _LenEl);
            }
            _Massiv.push_back(_boofer);
        }
    }
    void BaseData(int _siz, int _len)
    {
        _SizeMas = _siz;
        _LenEl = _len;
    }
    void Displey()
    {
        for (int i = 0; i < _Massiv.size(); i++)
        {
            cout << _Massiv[i] << " ";
        }
        cout << endl;
    }
    void SortAlf()
    {
        string _boofer;
        for (int k = 0; k < _Massiv.size(); k++)
        {
            for(int i = 0; i < _Massiv.size()-1; i++)
            {
                if (_Massiv[i].compare(_Massiv[i+1]) > 0)
                {
                    _boofer = _Massiv[i+1];
                    _Massiv[i+1] = _Massiv[i];
                    _Massiv[i] = _boofer;
                }
            }
        }
    }
    void Append_Element(string _element)
    {
        _Massiv.push_back(_element);
    }
    void Dublicate_Analize()
    {
        for(int i = 0; i < _Massiv.size()-1; i++)
        {
            if(_Massiv[i] == _Massiv[i+1])
            {
                _Massiv.erase(_Massiv.begin()+i);
            }
        }
    }
};
void Format(Delta _Massiv_1, Delta _Massiv_2, Delta _Gibridt, int _Index)
{
    _Massiv_1.SortAlf();
    _Massiv_2.SortAlf();
    _Massiv_1.Displey();
    _Massiv_2.Displey();
    for(int i = 0; i < _Massiv_1.GetSizeMas(); i++)
    {
        _Gibridt.Append_Element(_Massiv_1.Return_Element(i));
    }
    for(int i = 0; i < _Massiv_2.GetSizeMas(); i++)
    {
        _Gibridt.Append_Element(_Massiv_2.Return_Element(i));
    }
    _Gibridt.Displey();
    _Gibridt.SortAlf();
    _Gibridt.Dublicate_Analize();
    _Gibridt.Displey();
    cout << _Massiv_1.Return_Element(_Index) << " " << _Massiv_2.Return_Element(_Index) << endl;
}
int main()
{
    int _Sm, _Le, _P_Index;
    Delta _Mas1, _Mas2, _Gibrid;
    cin >> _Sm >> _Le;
    _Mas1.BaseData(_Sm, _Le);
    _Mas2.BaseData(_Sm, _Le);
    _Gibrid.BaseData(_Sm*2, _Le);
    _Mas1.MassivAdd();
    _Mas2.MassivAdd();
    cin >> _P_Index;
    Format(_Mas1, _Mas2, _Gibrid, _P_Index);
    return 0;
}
