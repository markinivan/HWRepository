#pragma once
#include <cmath>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstddef>
using elem_type = unsigned int;
class TBitField {
private:
	size_t bitLen;                      // длина битового поля (максимальное допустимое значение эл-та мн-ва, мощность универса)
	size_t memLen;                      // кол-во элементов, необходимое для хранения битового поля
	elem_type* pMem;                    // память для представления битового поля

	// индекс в pМем для бита pos
	size_t GetMemIndex(size_t pos) const noexcept;

	// битовая маска для бита pos
	elem_type GetMemMask(size_t pos) const noexcept;

	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf);

public:
	// обязательный функционал
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