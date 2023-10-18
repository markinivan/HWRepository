#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstddef>
using elem_type = unsigned int;
class TBitField {
private:
	size_t bitLen;                      // ����� �������� ���� (������������ ���������� �������� ��-�� ��-��, �������� ��������)
	size_t memLen;                      // ���-�� ���������, ����������� ��� �������� �������� ����
	elem_type* pMem;                    // ������ ��� ������������� �������� ����

	// ������ � p��� ��� ���� pos
	size_t GetMemIndex(size_t pos) const noexcept;

	// ������� ����� ��� ���� pos
	elem_type GetMemMask(size_t pos) const noexcept;

	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);

public:
	// ������������ ����������
	TBitField(size_t _BitLen);
	TBitField(const TBitField& bf);
	TBitField(TBitField&& bf) noexcept;
	~TBitField();

	TBitField& operator=(const TBitField& bf);
	TBitField& operator=(TBitField&& bf) noexcept;
	bool operator==(const TBitField& bf) const noexcept;
	bool operator!=(const TBitField& bf) const noexcept;
	bool test(size_t i) const;
	void set(size_t i);
	void reset(size_t i);
	TBitField  operator|(const TBitField& bf);
	TBitField  operator&(const TBitField& bf);
	TBitField  operator~(void);
	size_t size() const noexcept;
	void swap(TBitField& lhs, TBitField& rhs) noexcept;
	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);
};