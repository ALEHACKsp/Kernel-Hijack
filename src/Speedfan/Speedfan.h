#ifndef SPEEDFAN_H
#define SPEEDFAN_H
#pragma once

#include <Windows.h>
#include <stdint.h>


class Speedfan
{
public:
	BOOLEAN OnSetup();
	BOOLEAN ReadMSR(uint32_t Msr, uint64_t* Ret);
	VOID ExecuteKernelCallback(PVOID Func);
	BOOLEAN ReadPhysicalAddress(uint64_t physAddress, DWORD Size, LPVOID Return);
	BOOLEAN WritePhysicalAddress(uint64_t physAddress, DWORD Size, PVOID Src);
	~Speedfan();

	template <typename T, typename U>
	T ReadPhysicalAddress(U Address)
	{
		T Buff{ 0 };
		ReadPhysicalAddress((uint64_t)Address, sizeof(T), &Buff);
		return Buff;
	}

private:
	BOOLEAN DropDriver();
	BOOLEAN LoadDriver();

private:
	char m_szPath[MAX_PATH];
	HANDLE m_hDriver;
};

#endif // !SPEEDFAN_H

extern Speedfan* g_pSpdfan;
extern unsigned char SpeedfanShell[28664];