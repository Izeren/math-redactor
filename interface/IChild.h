#pragma once
#include <list>
#include <memory>
#include <Windows.h>
#include <iostream>
#include <string>
#include <atltypes.h>

class IChild : public std::enable_shared_from_this<IChild> {
protected:
	std::weak_ptr<IChild> parent;
	CRect rect;

	IChild(const CRect& rect, std::weak_ptr<IChild> parent, int depth = 0) :
		parent(parent),
		rect(rect)
	{
        UNREFERENCED_PARAMETER( depth );
	}
public:
	virtual ~IChild(){}

	virtual std::weak_ptr<IChild> GetParent() const;
	virtual void SetParent(const std::weak_ptr<IChild> _parent);

	virtual void SetRect(const CRect& _rect);
	virtual CRect GetRect();
	virtual void Resize() = 0;
};

inline std::weak_ptr<IChild> IChild::GetParent() const
{
	return parent;
}

inline void IChild::SetParent(const std::weak_ptr<IChild> _parent)
{
	this->parent = _parent;
}

inline CRect IChild::GetRect()
{
	return rect;
}

inline void IChild::SetRect(const CRect& _rect)
{
	this->rect = _rect;
}