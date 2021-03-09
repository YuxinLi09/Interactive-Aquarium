/**
 * \file Fish.cpp
 *
 * \author Yuxin Li
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
#include <cstdlib> 

using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
    CItem(aquarium, filename)
{
    MaxSpeedX = 10;
    MaxSpeedY = 10;
    MinSpeedX = 10;
    MinSpeedY = 10;
    mSpeedX = ((double)rand() / RAND_MAX);
    mSpeedY = ((double)rand() / RAND_MAX);
}


/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
    int signx = (mSpeedX > 0) ? 1 : -1;
    int signy = (mSpeedY > 0) ? 1 : -1;
    /*SetLocation(GetX() + (MinSpeedX + mSpeedX * (MaxSpeedX - MinSpeedX)) * elapsed,
        GetY() + (MinSpeedY + mSpeedY * (MaxSpeedY - MinSpeedY)) * elapsed);*/
    double speedX = signx * (MinSpeedX + abs(mSpeedX) * (MaxSpeedX - MinSpeedX));
    double speedY = signy * (MinSpeedY + abs(mSpeedY) * (MaxSpeedY - MinSpeedY));
    SetLocation(GetX() + speedX * elapsed,
        GetY() + speedY * elapsed);

    if (mSpeedX > 0) 
    {
        double wid = GetAquarium()->GetWidth() - 10.0 - GetItemWidth() / 2;
        if (GetX() > wid) {
            mSpeedX = -mSpeedX;

            SetMirror(mSpeedX < 0);
        }
    } 

    if (mSpeedX < 0)
    {
        double wid = 10.0 + GetItemWidth() / 2;
        if (GetX() < wid)
        {
            mSpeedX = -mSpeedX;

            SetMirror(mSpeedX < 0);
        }
    }

    if (mSpeedY > 0)
    {
        double high = GetAquarium()->GetHeight();
        double height = GetAquarium()->GetHeight() - 10.0 - GetItemHeight() / 2;

        if (GetY() > height) {

            mSpeedY = -mSpeedY;

        }
    }

    if (mSpeedY < 0)
    {
        double height = 10.0 + GetItemHeight() / 2;
        if (GetY() < height)
        {

            mSpeedY = -mSpeedY;

        }
    }
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode The item that is going to be saved
 */
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);
    itemNode->SetAttribute(L"speedX", mSpeedX);
    itemNode->SetAttribute(L"speedY", mSpeedY);
    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  derived class version that loads the speed
 * information of every items.
 *
 * \param node The Xml node we are loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mSpeedX = node->GetAttributeDoubleValue(L"speedX", 0);
    mSpeedY = node->GetAttributeDoubleValue(L"speedY", 0);
    SetMirror(mSpeedX < 0);
}