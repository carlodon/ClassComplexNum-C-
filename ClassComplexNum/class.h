#pragma once
#include <iostream>	//библиотека для потокового ввода, вывода
#include <cmath>	//математическая библиотека
							 
class Complex	//сам класс "Комлпексные числа"
{
private:
	float real, imag;	//действительная и мнимая часть числа
public:

	//Создаем конструктор с возможностью задавать значения
	//через список инициализации
	Complex(float re = 0.f, float im = 0.f): real(re), imag(im){};

	//Конструктор копирования
	Complex(const Complex &complex) //&complex ссылается на объект, чтобы не создавать  его повторно в стэке
	{
		real = complex.real;
		imag = complex.imag;
	};
	

	// Деструктор	(для приличия)
	~Complex ()
	{

	}

	//Перегружаем оператор присваивания
	Complex& operator=(Complex &complex)
	{
		real = complex.real;
		imag = complex.imag;
	}


	//Перегружаем оператор сложения
	Complex operator+(Complex &complex)
	{
		//Результатом операции является новый объект, очень важно вызывать конструктор прямо на return,
		//иначе объект удалится и ничего не вернется
		return Complex(real + complex.real, imag + complex.imag);
		//здесь и ниже real и imag выступают за действительную и мнимую часть первого числа
		//а complex.real и complex.imag для второго
	}
	
	//Перегружаем оператор вычитания
	Complex operator-(Complex &complex)
	{
		return Complex(real - complex.real, imag - complex.imag);
	}

	//Перегружаем оператор умножения
	Complex operator*(Complex &complex)
	{
		return Complex((real * complex.real) - (imag * complex.imag), (real * complex.imag) + (imag * complex.real));
	}

	//Перегружаем оператор деления
	Complex operator/(Complex &complex) 
	{
		float div, real, imag;
		div = complex.real * complex.real + complex.imag * complex.imag; //делитель
		real = ((this->real * complex.real) + (this->imag * complex.imag)) / div;
		imag = ((this->imag * complex.real) - (this->imag * complex.imag)) / div;
		return Complex(real, imag);
	}


	//Перегрузка оператора увеличения
	Complex& operator+=(Complex &complex)
	{
		//Создаем переменную буффер для хранения результатов
		//auto сам решит какой тип лучше использовать в том или ином случае
		auto buf = *this + complex;
		real = buf.real;
		imag = buf.imag;
		//Необходимо вернуть самого себя (*this - указатель сам на себя)
		return *this;
	}
	//Аналогично для операторов ниже
	//Перегрузка оператора уменьшения
	Complex& operator-=(Complex &complex)
	{
		auto buf = *this - complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}
	//Перегрузка оператора увеличения умножением
	Complex& operator*=(Complex &complex)
	{
		auto buf = *this * complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}
	//Перегрузка оператора уменьшения делением
	Complex& operator/=(Complex &complex)
	{
		auto buf = *this / complex;
		real = buf.real;
		imag = buf.imag;
		return *this;
	}

	//Перегрузка оператора равенства двух комплексных чисел
	bool operator==(Complex &complex)
	{
		return (real == complex.real) && (imag == complex.imag);
	}
	//Перегрузка оператора неравенства двух комплексных чисел
	bool operator!=(Complex &complex)
	{
		return !(*this == complex);
	}

	//Нахождение модуля комплексного числа
	float Abs()
	{
		return sqrt(real * real + imag * imag);
	}

	//Сопряженное комплексное число
	float Conj()
	{
		return (imag*=-1);
	}

	//Перегружаем оператор  потокового ввода
	//friend - дружественная функция
	friend std::istream& operator>>(std::istream &input, Complex &complex)
	{ 
		input >> complex.real;	//передаем объекты на ввод real и imag 
		input >> complex.imag;	//по ссылке
		return input;            
	}
	//Перегружаем оператор  потокового вывода
	//friend - дружественная функция
	friend std::ostream& operator<<(std::ostream &output, Complex &complex)
	{ 
		if(complex.imag > 0)
		{
			//передаем объекты на вывод real и imag по ссылке
			output << complex.real << " + " << complex.imag << 'i';
		}
		else output << complex.real << " - " << complex.imag*(-1) << 'i'; 
		return output;            
	}

	//функции для инкапсуляции, так как сами переменные заданы в private
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