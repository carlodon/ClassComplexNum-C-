#pragma once
#include <iostream>	//���������� ��� ���������� �����, ������
#include <cmath>	//�������������� ����������
							 
class Complex	//��� ����� "����������� �����"
{
private:
	float real, imag;	//�������������� � ������ ����� �����
public:

	//������� ����������� � ������������ �������� ��������
	//����� ������ �������������
	Complex(float re = 0.f, float im = 0.f): real(re), imag(im){};

	//����������� �����������
	Complex(const Complex &complex) //&complex ��������� �� ������, ����� �� ���������  ��� �������� � �����
	{
		real = complex.real;
		imag = complex.imag;
	};
	

	// ����������	(��� ��������)
	~Complex ()
	{

	}

	//����������� �������� ������������
	Complex& operator=(Complex &complex)
	{
		real = complex.real;
		imag = complex.imag;
	}


	//����������� �������� ��������
	Complex operator+(Complex &complex)
	{
		//����������� �������� �������� ����� ������, ����� ����� �������� ����������� ����� �� return,
		//����� ������ �������� � ������ �� ��������
		return Complex(real + complex.real, imag + complex.imag);
		//����� � ���� real � imag ��������� �� �������������� � ������ ����� ������� �����
		//� complex.real � complex.imag ��� �������
	}
	
	//����������� �������� ���������
	Complex operator-(Complex &complex)
	{
		return Complex(real - complex.real, imag - complex.imag);
	}

	//����������� �������� ���������
	Complex operator*(Complex &complex)
	{
		return Complex((real * complex.real) - (imag * complex.imag), (real * complex.imag) + (imag * complex.real));
	}

	//����������� �������� �������
	Complex operator/(Complex &complex) 
	{
		float div, real, imag;
		div = complex.real * complex.real + complex.imag * complex.imag; //��������
		real = ((this->real * complex.real) + (this->imag * complex.imag)) / div;
		imag = ((this->imag * complex.real) - (this->imag * complex.imag)) / div;
		return Complex(real, imag);
	}


	//���������� ��������� ����������
	Complex& operator+=(Complex &complex)
	{
		//������� ���������� ������ ��� �������� �����������
		//auto ��� ����� ����� ��� ����� ������������ � ��� ��� ���� ������
		auto buf = *this + complex;
		real = buf.real;
		imag = buf.imag;
		//���������� ������� ������ ���� (*this - ��������� ��� �� ����)
		return *this;
	}
	//���������� ��� ���������� ����
	//���������� ��������� ����������
	Complex& operator-=(Complex &complex)
	{
		auto buf = *this - complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}
	//���������� ��������� ���������� ����������
	Complex& operator*=(Complex &complex)
	{
		auto buf = *this * complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}
	//���������� ��������� ���������� ��������
	Complex& operator/=(Complex &complex)
	{
		auto buf = *this / complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}

	//���������� ��������� ��������� ���� ����������� �����
	bool operator==(Complex &complex)
	{
		return (real == complex.real) && (imag == complex.imag);
	}
	//���������� ��������� ����������� ���� ����������� �����
	bool operator!=(Complex &complex)
	{
		return !(*this == complex);
	}

	//���������� ������ ������������ �����
	float Abs()
	{
		return sqrt(real * real + imag * imag);
	}

	//����������� ����������� �����
	float Conj()
	{
		return (imag*=-1);
	}

	//����������� ��������  ���������� �����
	//friend - ������������� �������
	friend std::istream& operator>>(std::istream &input, Complex &complex)
	{ 
		input >> complex.real;	//�������� ������� �� ���� real � imag 
		input >> complex.imag;	//�� ������
		return input;            
	}
	//����������� ��������  ���������� ������
	//friend - ������������� �������
	friend std::ostream& operator<<(std::ostream &output, Complex &complex)
	{ 
		if(complex.imag > 0)
		{
			//�������� ������� �� ����� real � imag �� ������
			output << complex.real << " + " << complex.imag << 'i';
		}
		else output << complex.real << " - " << complex.imag*(-1) << 'i'; 
		return output;            
	}

	//������� ��� ������������, ��� ��� ���� ���������� ������ � private
	float GetImPart()
	{
		return imag;
	}

	float GetRePart()
	{
		return real;
	}

	void SetImPart(float im)
	{
		imag = im;
	}

	void SetRePart(float re)
	{
		real = re;
	}

};