/**
 * \file FishBeta.h
 *
 * \author Yuxin Li
 *
 * Class the implements a Beta fish
 */

#pragma once

#ifndef CFISHBETA_H
#define CFISHBETA_H

#include "Fish.h"
#include "XmlNode.h"
#include <memory>
#include <string>

 /**
  * Implements a Beta fish
  */
class CFishBeta : public CFish
{
public:
    CFishBeta(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

   // void SetMaxSpeed();

};

#endif