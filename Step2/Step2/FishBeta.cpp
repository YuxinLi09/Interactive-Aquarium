/**
 * \file FishBeta.cpp
 *
 * \author Yuxin Li
 */

#include "pch.h"
#include "FishBeta.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
    CFish(aquarium, FishBetaImageName)
{
    MinSpeedX = 50;
    MinSpeedY = 10;
    MaxSpeedX = 150;
    MaxSpeedY = 150;
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode, the item that is going to be saved
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"beta");
    return itemNode;
}