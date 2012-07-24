/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkGPUInterpolateImageFunction_h
#define __itkGPUInterpolateImageFunction_h

#include "itkInterpolateImageFunction.h"
#include "itkGPUInterpolatorBase.h"

namespace itk
{
/** \class GPUInterpolateImageFunction
 */
template< class TInputImage, class TCoordRep = float, class TParentImageFilter =
  InterpolateImageFunction< TInputImage, TCoordRep > >
class ITK_EXPORT GPUInterpolateImageFunction
  : public TParentImageFilter, public GPUInterpolatorBase
{
public:
  /** Standard class typedefs. */
  typedef GPUInterpolateImageFunction Self;
  typedef TParentImageFilter          Superclass;
  typedef SmartPointer< Self >        Pointer;
  typedef SmartPointer< const Self >  ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GPUInterpolateImageFunction, TParentImageFilter);

  /** ImageDimension constants */
  itkStaticConstMacro(InputImageDimension, unsigned int,
    TInputImage::ImageDimension);

  /** InputImageType typedef support. */
  typedef typename Superclass::InputImageType InputImageType;

  /** CoordRepType typedef support. */
  typedef typename Superclass::CoordRepType CoordRepType;

protected:
  GPUInterpolateImageFunction();
  ~GPUInterpolateImageFunction() {}
  void PrintSelf(std::ostream & os, Indent indent) const;

  virtual GPUDataManager::Pointer GetParametersDataManager() const;

private:
  GPUInterpolateImageFunction(const Self &); //purposely not implemented
  void operator=(const Self &);              //purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkGPUInterpolateImageFunction.hxx"
#endif

#endif
