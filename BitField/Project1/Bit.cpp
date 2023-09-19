#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_
#include <cmath>
#include <iostream>
#define SHIFT -1
#define ELSIZE 16
using elem_type = unsigned int;

class TBitField {
private:
	size_t bitLen;                      // ����� �������� ���� (������������ ���������� �������� ��-�� ��-��, �������� ��������)
	size_t memLen;                      // ���-�� ���������, ����������� ��� �������� �������� ����
	elem_type* pMem;                    // ������ ��� ������������� �������� ����

	// ������ � p��� ��� ���� pos
	size_t GetMemIndex(size_t pos) const noexcept {
		return (pos / ELSIZE);
	}

	// ������� ����� ��� ���� pos
	elem_type GetMemMask(size_t pos) const noexcept {
		size_t id = pos;
		while (id > ELSIZE-1) {
			id -= ELSIZE;
		}
		return pow(2,id);
	
	}

public:
	// ������������ ����������
	TBitField(size_t _BitLen) { // ����������� ������������ ����
		bitLen = _BitLen;
		memLen = (_BitLen / ELSIZE)+1;
		pMem = new elem_type[_BitLen];
	}                             
	TBitField(const TBitField& bf) {// ����������� �����������
		bitLen = bf.bitLen;
		memLen = bf.memLen;
		pMem = new elem_type[bitLen];
	}                        
	TBitField(TBitField&& bf) noexcept {// move-����������� (����������� ����������� bf � this)
		bitLen = bf.bitLen;
		memLen = bf.memLen;
		pMem = bf.pMem;
	}                    

	~TBitField() {// ����������
		delete[] pMem;
	}                                          

	TBitField& operator=(const TBitField& bf) {
		this->bitLen = bf.bitLen;
		this->memLen = bf.memLen;
		this->pMem = bf.pMem;
	}
	TBitField& operator=(TBitField&& bf) noexcept;
	bool operator==(const TBitField& bf) const noexcept {
		if (this->bitLen == bf.bitLen && this->memLen == bf.memLen && this->pMem == bf.pMem) {
			return 1;
		}
		else {
			return 0;
		}
	}
	bool operator!=(const TBitField& bf) const noexcept {
		if (this->bitLen == bf.bitLen && this->memLen == bf.memLen && this->pMem == bf.pMem) {
			return 0;
		}
		else {
			return 1;
		}
	}

	bool test(size_t i) const { // �������� �������� ���� i	
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
	void set(size_t i) { // ���������� ��� i
		if (i < bitLen) {
			size_t seg = this->GetMemIndex(i);
			pMem[seg] = pMem[seg] & this->GetMemMask(i);
		}
	}
	void reset(size_t i) {// �������� ��� i
		if (i < bitLen) {
			size_t seg = this->GetMemIndex(i);
			pMem[seg] = pMem[seg] & ~(this->GetMemMask(i));
		}
	}
	TBitField  operator|(const TBitField& bf) { // ���
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = pMem[i] | bf.pMem[i];
		}
	}              
	TBitField  operator&(const TBitField& bf) { // �
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = pMem[i] & bf.pMem[i];
		}
	}
	TBitField  operator~(void) { // ���������
		for (int i = 0; i < this->memLen; i++) {
			pMem[i] = ~pMem[i];
		}
	}
	// �������� ����� (�-�� �����)
	size_t size() const noexcept {
		return bitLen;
	}

	friend void swap(TBitField& lhs, TBitField& rhs) noexcept {
		if (lhs!=rhs) {
			TBitField tmp = lhs;
			lhs = rhs;
			rhs = tmp;
		}
	}

	// ����/�����
	friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf){
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
};
#endif  // INCLUDE_BITFIELD_H_
