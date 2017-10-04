// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
	if (mp < 0)
		throw "MaxPower is negative";
	BitField = TBitField(mp);
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.MaxPower)
{
	if (s.MaxPower < 0)
		throw "MaxPower is negative";
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf.GetLength())
{
	//MaxPower = bf.GetLength;
	//BitField = bf;
}

TSet::operator TBitField()// преобразование типа к битовому полю
{
	//MaxPower =
	//TSet temp(;
	//BitField = BitField | Elem;
	//return temp;
	return TSet(0);
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
  return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	int key = Elem / 32;
	if (BitField.GetBit(Elem)) return 1;
	else return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if (MaxPower != s.MaxPower) return 0;
	if (BitField != s.BitField) return 0;
	else return 1;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if (MaxPower != s.MaxPower) return 1;
	if (BitField != s.BitField) return 1;
	else return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	MaxPower = (MaxPower < s.MaxPower) ? s.MaxPower : MaxPower;
	BitField = BitField | s.BitField;
	return *this;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	BitField = BitField | Elem;
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	BitField = BitField & ~Elem;
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	MaxPower = (MaxPower > s.MaxPower) ? s.MaxPower : MaxPower;
	BitField = BitField & s.BitField;
	return *this;
}

TSet TSet::operator~(void) // дополнение
{
	BitField = ~BitField;
	return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int k;
	cin >> k;
	while (k > -1)
	{
		s.InsElem(k);
		cin >> k;
	}

	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	cout << "{";
	//for (int k = 0; k < s.GetMaxPower; k++)
		//cout << s.BitField.GetBit(k);
	cout << "}\n";
  return ostr;
}
