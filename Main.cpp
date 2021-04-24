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
		_numAllCharacters = _text.size();//文字数
	}
	void update() {
		_frame++;
		if (_frame%_freqency == 0) {//_freqency回に1回
			if (_numReturningCharacters < _numAllCharacters) {//まだ全ての文字を解放していない時に限り
				_numReturningCharacters++;//解放する文字数を1増やす
			}
		}
	}
	string getText() {
		return _text.substr(0, _numReturningCharacters);//解放している文字数分だけ返す
	}
};

int main() {
	RPGText *rpgtext = new RPGText("Himitsu", 4);
	for (int i = 0; i < 100; i++) {
		cout <<  i << " ";
		rpgtext->update();
		//getText関数で返された値をc言語の文字列に変換し、表示する関数に転送している
		cout << rpgtext->getText().c_str() << endl;
	}
	getchar();
	return 0;
}