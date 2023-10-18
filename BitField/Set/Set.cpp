#include "Set.h"
TSet::TSet(int mp) :bitField(mp), maxPower(mp) {};
TSet::TSet(const TSet& s) :bitField(s.bitField), maxPower(s.maxPower) {}
TSet::operator TBitField()	{
	return bitField;
}

size_t TSet::GetMaxPower() const noexcept {}

void TSet::InsElem(size_t Elem) {
	bitField.set(Elem);
}            // �������� ������� � ���������
void TSet::DelElem(size_t Elem) {
	bitField.reset(Elem);
}            // ������� ������� �� ���������
bool TSet::IsMember(size_t Elem) const {
	return bitField.test(Elem);
}     // ��������� ������� �������� � ���������

TSet TSet::operator+ (const int Elem) {
	InsElem(Elem);
	return *this;
}       // ����������� � ���������
TSet TSet::operator- (const int Elem) {
	DelElem(Elem);
	return *this;
}     // �������� � ���������
TSet TSet::operator+ (const TSet& s) {
	this->bitField | s.bitField;
	this->maxPower = this->bitField.size();
	return *this;
}        // �����������
TSet TSet::operator* (const TSet& s) {
	this->bitField & s.bitField;
	return *this;
}        // �����������
TSet TSet::operator~ () {
	~(this->bitField);
	return *this;
}                     // ����������

int TSet::operator== (const TSet& s) const {
	int count = 0;
	size_t Power = std::min(this->maxPower, s.maxPower);
	for (size_t i = 0; i < Power; i++) {
		if (this->bitField.test(i) == s.bitField.test(i)) {
			count++;
		}
	}
	return count;
}
int TSet::operator!= (const TSet& s) const {
	int count = 0;
	size_t Power = std::min(this->maxPower, s.maxPower);
	for (size_t i = 0; i < Power; i++) {
		if (this->bitField.test(i) == s.bitField.test(i)) {
			count++;
		}
	}
	return std::max(this->maxPower, s.maxPower) - count;
}
TSet& TSet::operator=(const TSet& s) {
	this->bitField == s.bitField;
	this->maxPower == s.maxPower;
	return *this;
}

std::istream& operator>>(std::istream& in, TSet& bf) {

}
std::ostream& operator<<(std::ostream& out, TSet& bf) {
	out << "[" << TBitField(bf) << "]";
	return out;
}