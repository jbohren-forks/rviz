/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_AXES_DISPLAY_H
#define RVIZ_AXES_DISPLAY_H

#include "rviz/display.h"

#include "rviz/properties/forwards.h"

namespace rviz
{
class Axes;
}

namespace rviz
{

/**
 * \class AxesDisplay
 * \brief Displays a set of XYZ axes at the origin
 */
class AxesDisplay : public Display
{
public:
  AxesDisplay();
  virtual ~AxesDisplay();

  void onInitialize();

  /**
   * \brief Set the parameters for the axes
   * @param length Length of each axis
   * @param radius Radius of each axis
   */
  void set( float length, float radius );

  void setLength( float length );
  float getLength() { return length_; }
  void setRadius( float radius );
  float getRadius() { return radius_; }

  const std::string& getFrame() { return frame_; }
  void setFrame(const std::string& frame);


  // Overrides from Display
  virtual void createProperties();
  virtual void update(float dt, float ros_dt);

protected:
  /**
   * \brief Create the axes with the current parameters
   */
  void create();

  // overrides from Display
  virtual void onEnable();
  virtual void onDisable();

  std::string frame_;
  float length_;                ///< Length of each axis
  float radius_;                ///< Radius of each axis
  Axes* axes_;      ///< Handles actually drawing the axes

  FloatPropertyWPtr length_property_;
  FloatPropertyWPtr radius_property_;
  TFFramePropertyWPtr frame_property_;
};

} // namespace rviz

 #endif
