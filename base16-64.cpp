#include<bits/stdc++.h>
#include<cstring>
#include<cstdlib>
using namespace std;

map<char, int> map_of_base16 = 
{
	{'a',10}, {'b',11}, {'c',12}, {'d',13}, {'e',14}, {'f',15}
};

map<int, char> map_of_base64;


void fillMapBase64(){
	
	int asciiA=65;
	for(int i=0; i<=25; i++, asciiA++){
		map_of_base64[i] = static_cast<char>(asciiA);
	}

	
	int asciia=97;
	for(int i=26; i<=51; i++, asciia++){
		map_of_base64[i] = static_cast<char>(asciia);
	}


	int value = 0;
	for(int i=52; i<=61; i++,value++){
		map_of_base64[i] = '0' + value;
	}

	map_of_base64[62] = '+';
	map_of_base64[63] = '/';

}

bool between0And9(char c){
	return c>='0' && c<='9';
}

string convertToBinary(int x, int bits){
	
	string result = "";

	for(int i=0; i<bits; ++i){
		result = to_string(x%2) + result;
		x = x/2;
	}

	return result;
}

string base16to2(string base16){
    string result = "";

    for(int i=0; i<base16.length(); ++i){
        if(between0And9(base16[i]))
        	result += convertToBinary(base16[i]-'0', 4);
        else{
        	//cout<<base16[i]<<endl;
        	//cout<<map_of_base16[(char)base16[i]]<<endl;
        	result += convertToBinary(map_of_base16[base16[i]], 4);
        }
    }

    return result;
}

int base2toDecimal(string base2){
	int result;
	int place=1;
	for(int i=base2.length()-1; i>=0; --i){
		result += (base2[i]-'0')*place;
		place=place*2;
	}
	return result;
}

string base2to64(string base2){
	string result;
	string revbase2 = base2;
	reverse(revbase2.begin(), revbase2.end());
	cout<<revbase2<<endl;

	for(int i=0; i<revbase2.length(); i=i+6){
		//int lastIndex = (i+6<revbase2.length())?(i+6):revbase2.length();
		int remain = revbase2.length()-i;

		int lengthOfchunk = (remain<6)?remain:6;

		cout<<i<<" "<<lengthOfchunk<<endl;
		cout<<revbase2<<endl;
		cout<<revbase2.substr(i, lengthOfchunk)<<endl;
		cout<<base2toDecimal(revbase2.substr(i, lengthOfchunk))<<endl;
		cout<<map_of_base64[base2toDecimal(revbase2.substr(i, lengthOfchunk))]<<endl;
		result = map_of_base64[base2toDecimal(revbase2.substr(i, lengthOfchunk))] + result;

	}

	cout<<result<<endl;

	return "";
}

string base16to64(string base16){
	string base2 = base16to2(base16);
	//cout<<base2<<endl;
	//base2to64(base16to2(base16));
	base2to64(base2);
	return "";

	//return base2to64(base16to2(base16));
}


int main(){
    string base16;
    cin>>base16;
    //cout<<base16<<endl;
    //cout<<static_cast<char>(65)<<endl;
    fillMapBase64();
    base16to64(base16);
    //cout<<map_of_base64[48]<<" "<<map_of_base64[54]<<" "<<map_of_base64[62]<<endl;
    //cout<<to_string(0)<<endl;
    //cout<<convertToBinary(5, 4)<<endl;
    //cout<<('1'-'0')<<endl;
    //cout<<base2toDecimal("0000001");
    //cout << base16to2(base16) <<endl;
    //cout<<base16to64(base16)<<endl;
    //string s = "1000110100010101";
    //cout<<s.substr(6,12)<<endl;
}