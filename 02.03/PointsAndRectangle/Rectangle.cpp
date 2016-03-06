#include"Rectangle.h"
#include<iostream>


//������� ������� ��������� ������������ ����� ��
//���������� �� ����� ��������� �� �������
//�������� �������� �� �������� ���������� ����� , ����� �� �������
//�� �� ����� �� �������� ���� ������ , �� ���� ������� ����������
#define min(a,b) ((a > b) ? b : a)

#define max(a,b) ((a > b) ? a : b)
 
#define abs(x) (x > 0) ? (x) : ((-1)*(x))

//����������� �� ������������� �� � ���� ����� �����
//���������������� ��������� �� ����� �� �����
void ReadRect(Rect& rect){

	ReadPnt(rect.A);
	ReadPnt(rect.B);

}

void PrintRect(const Rect& rect){

	if (!isValid(rect)){

		std::cout << "can't be drawn!";
		return;
	}

	//����� ���� ������ �� �������� ������
	int downOffset = min(rect.A.y, rect.B.y);

	//����� ������ �� ������ �� ���������� �� ����� ���
	int rightOffset = min(rect.A.x, rect.B.y);

	//����� �� ��������
	int rows = abs(rect.A.y - rect.B.y) + 1;

	//����� ��������
	int cols = abs(rect.A.x - rect.B.x) + 1;

	//���������� ,����� �� �� ����� �� ������� ������� ������
	int curOffset = downOffset;

	while (curOffset--)
		std::cout << std::endl;

	//������� ����� , ����� ������ �� � �����
	curOffset = rightOffset;
	while (curOffset--)
		std::cout << " ";

	for (int i = 0; i < cols; i++)
		std::cout << "*";

	std::cout << std::endl;


	//����������� ����� �� �������������
	for (int i = 1; i < rows - 1; i++){

		curOffset = rightOffset;
		while (curOffset--)
			std::cout << " ";

		std::cout << "*";
        
		for (int j = 1; j < cols - 1; j++)
			std::cout << " ";

		std::cout << "*" << std::endl;
	}


	//���������� ���, ���� �����
	curOffset = rightOffset;
	while (curOffset--)
		std::cout << " ";

	for (int i = 0; i < cols; i++)
		std::cout << "*";

	std::cout << std::endl;

}



bool isValid(const Rect& rect){

	if (rect.A.x < 0 || rect.A.y < 0)
		return false;

	if (rect.B.x < 0 || rect.B.y < 0)
		return false;


	if (rect.A.x == rect.B.x)
		return false;


	if (rect.A.y == rect.B.y)
		return false;


	return true;
}




bool isInside(const Point& pnt, const Rect& rect){

	//������� ��������� �� ���� ����� ����� , ����� �� � ���� ������ �� �������� ��� �����������
    // A(a1,a2) B(b1,b2) - ������� , ���� x(�1,�2) ��������� :
    // |a1<x1<b1
	// |a2<x2<b2
    //���������� ��� � ���� , ������ �� ����� ��� ���������� �� ����������� � ������ � ��� �������
	return (pnt.x > min(rect.A.x, rect.B.x)) && (pnt.x < max(rect.A.x, rect.B.x)) &&
		(pnt.y > min(rect.A.y, rect.B.y)) && (pnt.y < max(rect.A.y, rect.B.y));


}


//�� �� ��� ������� ,�� ����� ������������� �� ��������
//� ���������� �� ���� ,�� ���� �� ��������� �� ����� �� ����� ������������� �� ������� � ������
//
bool Collision(const Rect& first, const Rect& second){

	if (isInside(first.A, second))
		return true;

	if (isInside(first.B, second))
		return true;
	
	//����������� ���� �� ������ ����� D �� ������ ������������
	Point first_D;

	first_D.x = first.A.x;
	first_D.y = first.B.y;

	//���������� ���� �� ������� ��� ������
	if (isInside(first_D, second))
		return true;

	Point first_C;

	first_C.x = first.B.x;
	first_C.y = first.A.y;

	if (isInside(first_C, second))
		return true;


	//for the second rectangle's points
	if (isInside(second.A, first))
		return true;

	if (isInside(second.B, first))
		return true;

	Point second_D;

	second_D.x = second.A.x;
	second_D.y = second.B.y;

	if (isInside(second_D, first))
		return true;

	Point second_C;

	second_C.x = second.B.x;
	second_C.y = second.A.y;

	if (isInside(second_C, first))
		return true;


	//we have failed all the tests
	return false;
}