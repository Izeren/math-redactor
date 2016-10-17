#include "CEditControl.h"
#include "resource.h"

const int MIN_HEIGHT_DEFAULT = 16;
const int MIN_WIDTH_DEFAULT = 30;
const int MIN_SIZE_SYMBOL = 8;

CEditControl::CEditControl()
{
	height = MIN_HEIGHT_DEFAULT;
	width = MIN_WIDTH_DEFAULT;
	handle = 0;
}

CEditControl::~CEditControl()
{
}

bool CEditControl::Create(HWND parentHandle) {
	handle = CreateWindowEx(0, L"EDIT", 0, WS_CHILD | WS_VISIBLE | ES_LEFT ,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, parentHandle, 0, GetModuleHandle(0), 0);
	SetFocus(handle);
	return handle != 0;
}

void CEditControl::Show(int cmdShow)
{
	ShowWindow(handle, cmdShow);
}

HWND CEditControl::GetHandle() {
	return handle;
}

int CEditControl::GetHeight() const {
	return height;
}

int CEditControl::GetWidth() const {
	return width;
}

void CEditControl::SetHeight(int height) {
	if (height >= MIN_HEIGHT_DEFAULT) {
		this->height = height;
	}
}

void CEditControl::SetWidth(int width) {
	if (width >= MIN_WIDTH_DEFAULT) {
		this->width = width;
	}
}

void CEditControl::SetCountSymbols(int countSymbols) {
	//if (countSymbols >= 0) {
		this->countSymbols = countSymbols;
		SetWidth(this->countSymbols * MIN_SIZE_SYMBOL);
		SetWindowPos(handle, HWND_TOP, 0, 0, width, height, SWP_NOMOVE);
//	}
}

int CEditControl::GetCountSymbols() const {
	return countSymbols;
}

std::wstring CEditControl::GetText() const {
	int length = SendMessage(handle, WM_GETTEXTLENGTH, 0, 0);
	length++;
	std::wstring text;
	text.resize(length);
	::GetWindowText(handle, (LPWSTR)text.c_str(), length);
	return text;
}