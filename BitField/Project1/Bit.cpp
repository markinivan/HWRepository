#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_
#include <Bit.h>
#define SHIFT -1
#define ELSIZE 16
size_t TBitField::GetMemIndex(size_t pos) const noexcept {
		return (pos / ELSIZE);
	}

	// битовая маска для бита pos
	elem_type TBitField::GetMemMask(size_t pos) const noexcept {
		size_t id = pos;
		while (id > ELSIZE-1) {
			id -= ELSIZE;
		}
		return pow(2,id);
	
	}
	// обязательный функционал
	TBitField::TBitField(size_t _BitLen) { // конструктор специального вида
		bitLen = _BitLen;
		memLen = (_BitLen / ELSIZE)+1;
		pMem = new elem_type[_BitLen];
	}                             
	TBitField::TBitField(const TBitField& bf) {// конструктор копирования
		bitLen = bf.bitLen;
		memLen = bf.memLen;
		pMem = new elem_type[bitLen];
	}                        
	TBitField::TBitField::TBitField(TBitField&& bf) noexcept {// move-конструктор (перемещение содержимого bf в this)
		bitLen = bf.bitLen;
		memLen = bf.memLen;
		pMem = bf.pMem;
	}                    

	TBitField::~TBitField() {// деструктор
		delete[] pMem;
	}                                          

	TBitField& TBitField::operator=(const TBitField& bf) {
		this->bitLen = bf.bitLen;
		this->memLen = bf.memLen;
		this->pMem = bf.pMem;
		return *this;
	}
	bool TBitField::operator==(const TBitField& bf) const noexcept {
		if (this->bitLen == bf.bitLen && this->memLen == bf.memLen && this->pMem == bf.pMem) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool TBitField::operator!=(const TBitField& bf) const noexcept {
		if (this->bitLen == bf.bitLen && this->memLen == bf.memLen && this->pMem == bf.pMem) {
			return 0;
		}
		else {
			return 1;
		}
	}

	bool TBitField::test(size_t i) const { // получить значение бита i	
		if (i < bitLen) {
			elem_type mask = this->GetMemMask(i);
			if ((mask & pMem[this->GetMemIndex(i)]) == mask){
				return 1;
			}
			else {
				return 0;
			}
		}
	}                             
	void TBitField::set(size_t i) { // установить бит i
		if (i < bitLen) {
			size_t seg = this->GetMemIndex(i);
			pMem[seg] = pMem[seg] | this->GetMemMask(i);
		}
	}
	void TBitField::reset(size_t i) {// очистить бит i
		if (i < bitLen) {
			size_t seg = this->GetMemIndex(i);
			pMem[seg] = pMem[seg] & ~(this->GetMemMask(i));
		}
	}
	TBitField  TBitField::operator|(const TBitField& bf) { // или
		size_t new_memLen = std::max(this->memLen,bf.memLen);
		if (this->memLen != new_memLen) {
			auto* new_pMem = new elem_type[this->memLen];
			memcpy(new_pMem, pMem, memLen * sizeof(elem_type));
			this->pMem = new_pMem;
			this->memLen = new_memLen;
		}
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = pMem[i] | bf.pMem[i];
		}
		return *this;
	}              
	TBitField  TBitField::operator&(const TBitField& bf) { // и
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = pMem[i] & bf.pMem[i];
		}
		return *this;
	}
	TBitField  TBitField::operator~(void) { // отрицание
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = ~pMem[i];
		}
		return *this;
	}
	// получить длину (к-во битов)
	size_t TBitField::size() const noexcept {
		return bitLen;
	}

	void TBitField::swap(TBitField& lhs, TBitField& rhs) noexcept {
		if (lhs!=rhs) {
			TBitField tmp = lhs;
			lhs = rhs;
			rhs = tmp;
		}
	}
// ввод/вывод
  std::ostream& operator<<(std::ostream& ostr, const TBitField& bf) {
	ostr << "[";
	for (int i = 0; i < bf.bitLen; i++) {
		if (bf.test(i)) {
			if (i != 0) {
				ostr << ", ";
			}
			ostr << i;
		}
	}
	ostr << "]";
	return ostr;
}

#endif  // INCLUDE_BITFIELD_H_
