#pragma once
#include "Main.h"
#include "CypherLib.h"
#define str String^

using namespace System;
/*
void ChangeScape(int ow, System::Windows::Forms::Form^ a)
{
	switch (ow)
	{
	case 0:
		a->input->Clear();
		a->key->Clear();
		a->output->Clear();
		a->input->Enabled = true;
		a->key->Enabled = true;
		a->encrypt->Enabled = true;
		a->decrypt->Enabled = true;
		break;
	case 1:
		a->input->Clear();
		a->key->Clear();
		a->output->Clear();
		a->input->Enabled = true;
		a->key->Enabled = true;
		a->encrypt->Enabled = true;
		a->decrypt->Enabled = true;
		break;
	case 2:
		a->input->Clear();
		a->key->Clear();
		a->output->Clear();
		a->input->Enabled = true;
		a->key->Enabled = false;
		a->encrypt->Enabled = true;
		a->decrypt->Enabled = true;
		break;
	}
}
*/

bool Checker(array<wchar_t>^ arr, char switch_on)
{
	if (arr->Length <= 0)
		return 0;
	switch (switch_on)
	{
	case 'L':
		for (int i = 0; i < arr->Length; i++)
			if (!Char::IsLetter(arr[i]) && !(arr[i] == ' '))
				return 0;
		break;
	case 'D':
		for (int i = 0; i < arr->Length; i++)
			if (!(Char::IsDigit(arr[i]) || arr[i] == ' ' || arr[i] == '-'))
				return 0;
		break;
	case 'M':
		for (int i = 0; i < arr->Length; i++)
			if (!(arr[i] == '.' || arr[i] == '-' || arr[i] == '/' || arr[i] == ' '))
				return 0;
		break;
	default:
		break;
	}
	return 1;
}

auto Encrypt(int InCipher, str InString, str InKey)
{
	System::String^ out = Convert::ToString("ERROR");
	InString = InString->ToUpper();
	if (!Checker(InString->ToCharArray(), 'L'))
		return out;
	switch (InCipher)
	{
	case 0:
		if (!Checker(InKey->ToCharArray(), 'D'))
			break;
		if (!System::String::IsNullOrEmpty(InKey))
			out = Caesar(InString, Convert::ToInt32(InKey));
		else
			out = Caesar(InString, 1);
		break;
	case 1:
		if (!Checker(InKey->ToCharArray(), 'L') && !System::String::IsNullOrEmpty(InKey))
			break;
		InString = InString->Replace((wchar_t)'J', (wchar_t)'I');
		out = PolybiusEncrypt(InString, InKey);
		break;
	case 2:
		out = MorseEncrypt(InString);
		break;
	case 3:
		if ((InKey->Length != InString->Length) || (!Checker(InKey->ToCharArray(), 'L')))
			break;
		InKey = InKey->ToUpper();
		out = VingenereEncrypt(InString, InKey);
		break;
	case 4:
		if ((System::String::IsNullOrEmpty(InKey)) || (!Checker(InKey->ToCharArray(), 'D')))
			break;
		while ((InString->Length % Convert::ToInt32(InKey)) != 0)
			InString += (wchar_t)' ';
		out = ScytaleEncrypt(InString, Convert::ToInt32(InKey));
		break;
	case 5:
		if (System::String::IsNullOrEmpty(InKey))
			break;
		out = BookEncrypt(InString, InKey);
		break;
	}
	return out;
}

auto Decrypt(int InCipher, str InString, str InKey)
{
	System::String^ out = Convert::ToString("ERROR");
	InString = InString->ToUpper();
	switch (InCipher)
	{
	case 0:
		if (!Checker(InString->ToCharArray(), 'L'))
			break;
		if (!System::String::IsNullOrEmpty(InKey))
			out = Caesar(InString, -Convert::ToInt32(InKey));
		else
			out = Caesar(InString, -1);
		break;
	case 1:
		if (!Checker(InString->ToCharArray(), 'D'))
			break;
		if (!Checker(InKey->ToCharArray(), 'L') && !System::String::IsNullOrEmpty(InKey))
			break;
		InKey = InKey->ToUpper();
		out = PolybiusDecrypt(InString, InKey);
		break;
	case 2:
		if (!Checker(InString->ToCharArray(), 'M'))
			break;
		out = MorseDecrypt(InString);
		break;
	case 3:
		if (!Checker(InString->ToCharArray(), 'L'))
			break;
		if ((InKey->Length != InString->Length) || (!Checker(InKey->ToCharArray(), 'L')))
			break;
		InKey = InKey->ToUpper();
		out = VingenereDecrypt(InString, InKey);
		break;
	case 4:
		if (!Checker(InString->ToCharArray(), 'L'))
			break;
		if ((System::String::IsNullOrEmpty(InKey)) || (!Checker(InKey->ToCharArray(), 'D')))
			break;
		while ((InString->Length % Convert::ToInt32(InKey)) != 0)
			InString += (wchar_t)' ';
		return ScytaleDecrypt(InString, Convert::ToInt32(InKey));
	case 5:
		if (!Checker(InString->ToCharArray(), 'D'))
			break;
		out = BookDecrypt(InString, InKey);
		break;
	default:
		break;
	}
	return out;
}
