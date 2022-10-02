#pragma once
#include <algorithm>
#include <iostream>
#define str String^ 

using namespace System;

#pragma region Caesar Code

auto Caesar(str InString, int k)
{
	k %= 26;
	auto z = InString->ToCharArray();
	for (int i = 0; i < z->Length; i++)
	{
		if (z[i] == ' ')
			continue;
		z[i] += k;
		if (z[i] > 'Z')
			z[i] = z[i] - 26;
		if (z[i] < 'A')
			z[i] = z[i] + 26;
	}
	auto out = gcnew String(z);
	return out;
}

#pragma endregion

#pragma region Polybius Square

struct alp {
	char l;
	int pos;
	alp()
	{
		l = ' ';
		pos = NULL;
	}
};

bool Pcmp(alp a, alp b)
{
	if ((a.pos == -1) && (b.pos == -1))
		return a.l < b.l;
	else
		return a.pos < b.pos;
}

auto PolybiusKeyGenerator(str k, char key[25])
{
	alp a[26];
	for (int i = 0; i < 26; i++)
	{
		if (k->IndexOf((wchar_t)'A' + i) == -1)
			a[i].pos = INT_MAX;
		else
			a[i].pos = k->IndexOf('A' + i);
		a[i].l = 'A' + i;
	}
	if ((a[8].pos != INT_MAX) || (a[9].pos != INT_MAX))
	{
		if (a[8].pos == INT_MAX)
		{
			std::swap(a[8], a[25]);
			a[9].l = 'I';
		}
		if (a[9].pos == INT_MAX)
			std::swap(a[9], a[25]);
	}
	else
		std::swap(a[9], a[25]);
	std::sort(a, a + 25, Pcmp);
	for (int i = 0; i < 25; i++)
		key[i] = a[i].l;
	return key;
}

auto CharNumSwap(int a)
{
	switch (a)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	default:
		return '!';
	}
}

auto NumCharSwap(char a)
{
	switch (a)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	default:
		return -1;
	}
}

auto PolybiusDecrypt(str InString, str k)
{
	int* t = new int[InString->Length];
	array<wchar_t>^ ts = InString->ToCharArray();
	char key[25] = { 'A', 'B', 'C', 'D', 'E',
					'F', 'G', 'H', 'I', 'K',
					'L', 'M', 'N', 'O', 'P',
					'Q', 'R', 'S', 'T', 'U',
					'V', 'W', 'X', 'Y', 'Z' };
	if (String::IsNullOrEmpty(k) == 0)
		PolybiusKeyGenerator(k, key);
	auto tmp = InString->Split();
	//break array tmp into digits and convert them to letters
	str out;
	for (int i = 0; i < tmp->Length; i++)
	{
		auto z = tmp[i]->ToCharArray();
		if (z->Length != 2)
			continue;
		int x = NumCharSwap(z[0]), y = NumCharSwap(z[1]);
		if ((x == -1) || (y == -1))
			return Convert::ToString("ERROR");
		out += Convert::ToChar(key[(x - 1) * 5 + y - 1]);
	}
	return out;
}

auto PolybiusEncrypt(str InString, str k)
{
	int* t = new int[InString->Length];
	array<wchar_t>^ ts = InString->ToCharArray();
	char key[25] = { 'A', 'B', 'C', 'D', 'E',
					'F', 'G', 'H', 'I', 'K',
					'L', 'M', 'N', 'O', 'P',
					'Q', 'R', 'S', 'T', 'U',
					'V', 'W', 'X', 'Y', 'Z' };
	if (String::IsNullOrEmpty(k) == 0)
		PolybiusKeyGenerator(k, key);
	for (int i = 0; i < InString->Length; i++)
	{
		if (ts[i] == ' ')
		{
			t[i] = 0;
			continue;
		}
		for (int j = 0; j < 25; j++)
			if (key[j] == ts[i])
			{
				t[i] = (((j / 5) + 1) * 10) + j % 5 + 1;
				break;
			}
	}
	str out;
	for (int i = 0; i < InString->Length; i++)
	{
		char t1 = CharNumSwap(t[i] / 10), t2 = CharNumSwap(t2 = t[i] % 10);
		if ((t1 == '!') || (t2 == '!'))
		{
			if (t[i] == 0)
				continue;
			else
				return Convert::ToString("ERROR");
		}
		str tt;
		tt += Convert::ToChar(t1);
		tt += Convert::ToChar(t2);
		out += tt + Convert::ToChar(' ');
	}
	return out;
}

#pragma endregion

#pragma region Morse Code

auto CharEncrypt(wchar_t in)
{
	if (in == 'A')
		return Convert::ToString(".-");
	if (in == 'B')
		return Convert::ToString("-...");
	if (in == 'C')
		return Convert::ToString("-.-.");
	if (in == 'D')
		return Convert::ToString("-..");
	if (in == 'E')
		return Convert::ToString(".");
	if (in == 'F')
		return Convert::ToString("..-.");
	if (in == 'G')
		return Convert::ToString("--.");
	if (in == 'H')
		return Convert::ToString("....");
	if (in == 'I')
		return Convert::ToString("..");
	if (in == 'J')
		return Convert::ToString(".---");
	if (in == 'K')
		return Convert::ToString("-.-");
	if (in == 'L')
		return Convert::ToString(".-..");
	if (in == 'M')
		return Convert::ToString("--");
	if (in == 'N')
		return Convert::ToString("-.");
	if (in == 'O')
		return Convert::ToString("---");
	if (in == 'P')
		return Convert::ToString(".--.");
	if (in == 'Q')
		return Convert::ToString("--.-");
	if (in == 'R')
		return Convert::ToString(".-.");
	if (in == 'S')
		return Convert::ToString("...");
	if (in == 'T')
		return Convert::ToString("-");
	if (in == 'U')
		return Convert::ToString("..-");
	if (in == 'V')
		return Convert::ToString("...-");
	if (in == 'W')
		return Convert::ToString(".--");
	if (in == 'X')
		return Convert::ToString("-..-");
	if (in == 'Y')
		return Convert::ToString("-.--");
	if (in == 'Z')
		return Convert::ToString("--..");
}

auto CharDecrypt(str in)
{
	if (in == ".-")
		return Convert::ToChar('A');
	if (in == "-...")
		return Convert::ToChar('B');
	if (in == "-.-.")
		return Convert::ToChar('C');
	if (in == "-..")
		return Convert::ToChar('D');
	if (in == ".")
		return Convert::ToChar('E');
	if (in == "..-.")
		return Convert::ToChar('F');
	if (in == "--.")
		return Convert::ToChar('G');
	if (in == "....")
		return Convert::ToChar('H');
	if (in == "..")
		return Convert::ToChar('I');
	if (in == ".---")
		return Convert::ToChar('J');
	if (in == "-.-")
		return Convert::ToChar('K');
	if (in == ".-..")
		return Convert::ToChar('L');
	if (in == "--")
		return Convert::ToChar('M');
	if (in == "-.")
		return Convert::ToChar('N');
	if (in == "---")
		return Convert::ToChar('O');
	if (in == ".--.")
		return Convert::ToChar('P');
	if (in == "--.-")
		return Convert::ToChar('Q');
	if (in == ".-.")
		return Convert::ToChar('R');
	if (in == "...")
		return Convert::ToChar('S');
	if (in == "-")
		return Convert::ToChar('T');
	if (in == "..-")
		return Convert::ToChar('U');
	if (in == "...-")
		return Convert::ToChar('V');
	if (in == ".--")
		return Convert::ToChar('W');
	if (in == "-..-")
		return Convert::ToChar('X');
	if (in == "-.--")
		return Convert::ToChar('Y');
	if (in == "--..")
		return Convert::ToChar('Z');
}

auto MorseEncrypt(str InString)
{
	str out;
	auto lib = InString->ToCharArray();
	for (int i = 0; i < lib->Length; i++)
	{
		if (lib[i] == ' ')
			out += Convert::ToString("/ ");
		else
			out += CharEncrypt(lib[i]) + Convert::ToString(" ");
	}
	return out;
}

auto MorseDecrypt(str InString)
{
	str out;
	auto lib = InString->Split();
	for (int i = 0; i < lib->Length; i++)
	{
		if (lib[i] == "/")
			out += Convert::ToString(" ");
		else
			out += CharDecrypt(lib[i]);
	}
	return out;
}

#pragma endregion

#pragma region Vingenere Cipher

auto VingenereEncrypt(str InString, str InKey)
{
	auto s = InString->ToCharArray(), k = InKey->ToCharArray();
	str out;
	for (int i = 0; i < s->Length; i++)
	{
		if (s[i] == ' ')
			continue;
		auto t = s[i] + (k[i]-65);
		if (t > 'Z')
			t -= 26;
		out += (wchar_t)t;
	}
	return out;
}

auto VingenereDecrypt(str InString, str InKey)
{
	auto s = InString->ToCharArray(), k = InKey->ToCharArray();
	str out;
	for (int i = 0; i < s->Length; i++)
	{
		if (s[i] == ' ')
			continue;
		auto t = s[i] - (k[i]-65);
		if (t < 'A')
			t += + 26;
		out += (wchar_t)t;
	}
	return out;
}

#pragma endregion

#pragma region Scytale Code

auto ScytaleEncrypt(str InString, int InKey)
{
	auto pro = InString->ToCharArray();
	str out;
	for (int i = 0; i < InKey; i++)
		for (int j = 0; j < pro->Length / InKey; j++)
			out += pro[i + (InKey * j)];
	return out;
}

auto ScytaleDecrypt(str InString, int InKey)
{
	auto pro = InString->ToCharArray();
	str out;
	for (int i = 0; i < InString->Length / InKey; i++)
		for (int j = 0; j < InKey; j++)
			out += pro[i + (j * (InString->Length / InKey))];
	return out;
}

#pragma endregion

#pragma region Book Cipher

ref class index
{
public:
	int pos;
	str word;
	index()
	{
		pos = 0;
		word = L" ";
	}
	index(int P, str W)
	{
		pos = P;
		word = W;	
	}
protected:
	~index()
	{
		pos = NULL;
		delete word;
	}
public:
	bool operator < (index^ other)
	{
		if (String::IsNullOrEmpty(other->word))
			return 1;
		if (String::IsNullOrEmpty(this->word))
			return 0;
		if (this->word[0] == other->word[0])
			return this->pos < other->pos;
		else
			return this->word[0] < other->word[0];
	}
};

void IndexSort(array<index^>^ in, int n)
{
	for (int i = 0; i < n; i++)
	{
		index^ tmp = in[i];
		for (int j = i; j < n; j++)
		{
			if (in[j] < tmp)
			{
				int z = tmp->pos;
				str y = tmp->word;
				tmp->pos = in[j]->pos;
				tmp->word = in[j]->word;
				in[j]->word = y;
				in[j]->pos = z;
			}
		}
		in[i] = tmp;
	}
}

auto BookKeyGenerator(array<str>^ in)
{
	array<index^>^ key = gcnew array<index^>(in->Length);
	for (int i = 0; i < in->Length; i++)
	{
		while (!(String::IsNullOrEmpty(in[i]) || Char::IsLetter(in[i][0])))
			in[i] = in[i]->Remove(0, 1);
		while (!(String::IsNullOrEmpty(in[i]) || Char::IsLetter(in[i][in[i]->Length - 1])))
			in[i] = in[i]->Remove(in[i]->Length - 1, 1);
		key[i] = gcnew index(i, in[i]->ToUpper());
	}
	IndexSort(key, key->Length);
	return key;
}

auto BookEncrypt(str InString, str InKey)
{
	auto rand = gcnew System::Random(System::DateTime::Now.Ticks);
	array<index^>^ key = BookKeyGenerator(InKey->Split());
	str out;
	for (int i = 0; i < InString->Length; i++)
	{
		auto curChar = InString[i];
		bool mode = false, notFound = false;
		int splitBegin = -1, splitEnd = -1;
		for (int j = 0; j < key->Length; j++)
		{
			if (System::String::IsNullOrEmpty(key[j]->word))
			{
				if (mode)
					splitEnd = j;
				else
					notFound = true;
				break;
			}
			if (key[j]->word[0] == curChar && !mode)
			{
				splitBegin = j;
				mode = true;
				continue;
			}
			if (key[j]->word[0] != curChar && mode)
			{
				splitEnd = j;
				break;
			}
		}
		if (!notFound)
		{
			int next = rand->Next(splitBegin, splitEnd);
			out += System::Convert::ToSingle(key[next]->pos) + L" ";
		}
		else
			out += L"-1 ";
	}
	return out;
}
auto BookDecrypt(str InString, str InKey)
{
	auto key = BookKeyGenerator(InKey->Split());
	auto check = InString->Trim()->Split();
	System::String^ out;
	for (int i = 0; i < check->Length; i++)
	{
		int tmp = System::Convert::ToInt32(check[i]), j = 0;
		if (tmp == -1)
		{
			out += L"~";
			continue;
		}
		while (tmp != key[j]->pos)
			j++;
		out += System::Convert::ToString(key[j]->word[0]);
	}
	return out;
}

#pragma endregion

#pragma region Rail Fence Code

#pragma endregion