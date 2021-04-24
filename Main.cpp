#include<iostream>
using namespace std;

class RPGText {
private:
	string _text;
	int _numReturningCharacters=0;
	int _numAllCharacters;
	int _freqency;
	int _frame=0;
public:
	RPGText(string text, int freqency) {
		_text = text;
		_freqency = freqency;
		_numAllCharacters = _text.size();//������
	}
	void update() {
		_frame++;
		if (_frame%_freqency == 0) {//_freqency���1��
			if (_numReturningCharacters < _numAllCharacters) {//�܂��S�Ă̕�����������Ă��Ȃ����Ɍ���
				_numReturningCharacters++;//������镶������1���₷
			}
		}
	}
	string getText() {
		return _text.substr(0, _numReturningCharacters);//������Ă��镶�����������Ԃ�
	}
};

int main() {
	RPGText *rpgtext = new RPGText("Himitsu", 4);
	for (int i = 0; i < 100; i++) {
		cout <<  i << " ";
		rpgtext->update();
		//getText�֐��ŕԂ��ꂽ�l��c����̕�����ɕϊ����A�\������֐��ɓ]�����Ă���
		cout << rpgtext->getText().c_str() << endl;
	}
	getchar();
	return 0;
}