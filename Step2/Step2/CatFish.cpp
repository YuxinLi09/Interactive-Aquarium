/**
 * \file FishBeta.cpp
 *
 * \author Yuxin Li
 */

#include "pch.h"
#include "CatFish.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CatFishImageName = L"images/catfish.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CCatFish::CCatFish(CAquarium* aquarium) :
    CFish(aquarium, CatFishImageName)
{
    MinSpeedX = 5;
    MinSpeedY = 5;
    MaxSpeedX = 20;
    MaxSpeedY = 20;
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode, the item that is going to be saved
 */
std::shared_ptr<xmlnode::CXmlNode>
CCatFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"catfish");
    return itemNode;
}
