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

bool Checker(array<wchar_t>^ a, char switch_on)
{
	if (a->Length <= 0)
		return 0;
	switch (switch_on)
	{
	case 'L':
		for (int i = 0; i < a->Length; i++)
			if (!Char::IsLetter(a[i]) && !(a[i]==' '))
				return 0;
		break;
	case 'D':
		for (int i = 0; i < a->Length; i++)
			if (!(Char::IsDigit(a[i]) || a[i] == ' '))
				return 0;
		break;
	case 'M':
		for (int i = 0; i < a->Length; i++)
			if (!(a[i]=='.' || a[i]=='-' || a[i]=='/' || a[i] == ' '))
				return 0;
		break;
	default:
		break;
	}
	return 1;
}

auto Encrypt(int inc, str ins, str ink)
{
	ins = ins->ToUpper();
	if (!Checker(ins->ToCharArray(), 'L'))
		return Convert::ToString("ERROR");
	switch (inc)
	{
	case 0:
		if (!System::String::IsNullOrEmpty(ink))
			return Caesar(ins, Convert::ToInt32(ink));
		else
			return Caesar(ins, 1);
	case 1:
		ins = ins->Replace((wchar_t)'J', (wchar_t)'I');
		ink = ink->ToUpper();
		return PolybiusEncrypt(ins, ink);
	case 2:
		return MorseEncrypt(ins);
		break;
	case 3:
		if (ink->Length != ins->Length)
			break;
		ink = ink->ToUpper();
		return VingenereEncrypt(ins, ink);
		break;
	case 4:
		if (System::String::IsNullOrEmpty(ink))
			break;
		while ((ins->Length % Convert::ToInt32(ink)) != 0)
			ins += (wchar_t)' ';
		return ScytaleEncrypt(ins, Convert::ToInt32(ink));
	case 5:
		if (System::String::IsNullOrEmpty(ink))
			break;
		return BookEncrypt(ins, ink);
	default:
		break;
	}
	return Convert::ToString("ERROR");
}

auto Decrypt(int inc, str ins, str ink)
{
	ins = ins->ToUpper();
	switch (inc)
	{
	case 0:
		if (!Checker(ins->ToCharArray(), 'L'))
			break;
		if (!System::String::IsNullOrEmpty(ink))
			return Caesar(ins, -Convert::ToInt32(ink));
		return Caesar(ins, -1);
	case 1:
		if (!Checker(ins->ToCharArray(), 'D'))
			break;
		ink = ink->ToUpper();
		return PolybiusDecrypt(ins, ink);
	case 2:
		if (!Checker(ins->ToCharArray(), 'M'))
			break;
		return MorseDecrypt(ins);
		break;
	case 3:
		if (!Checker(ins->ToCharArray(), 'L'))
			break;
		if (ink->Length != ins->Length)
			break;
		ink = ink->ToUpper();
		return VingenereDecrypt(ins, ink);
		break;
	case 4:
		if (!Checker(ins->ToCharArray(), 'L'))
			break;
		if (System::String::IsNullOrEmpty(ink))
			break;
		while ((ins->Length % Convert::ToInt32(ink)) != 0)
			ins += (wchar_t)' ';
		return ScytaleDecrypt(ins, Convert::ToInt32(ink));
	case 5:

	default:
		break;
	}
	return Convert::ToString("ERROR");
}
