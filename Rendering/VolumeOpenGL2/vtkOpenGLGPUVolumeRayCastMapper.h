/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOpenGLProjectedTetrahedraMapper.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#ifndef __vtkOpenGLGPUVolumeRayCastMapper_h
#define __vtkOpenGLGPUVolumeRayCastMapper_h

#include "vtkVolumeOpenGL2Module.h" // For export macro

#include <vtkGPUVolumeRayCastMapper.h>

#include <vtkSetGet.h>

//----------------------------------------------------------------------------
class VTKVOLUMEOPENGL2_EXPORT vtkOpenGLGPUVolumeRayCastMapper :
  public vtkGPUVolumeRayCastMapper
{
  public:
    static vtkOpenGLGPUVolumeRayCastMapper* New();

    vtkTypeMacro(vtkOpenGLGPUVolumeRayCastMapper, vtkGPUVolumeRayCastMapper);
    void PrintSelf( ostream& os, vtkIndent indent );

  protected:
    vtkOpenGLGPUVolumeRayCastMapper();
    ~vtkOpenGLGPUVolumeRayCastMapper();

    // Description:
    // Build vertex and fragment shader for the volume rendering
    void BuildShader(vtkRenderer* ren, vtkVolume* vol, int noOfComponents);

    // Description:
    // Rendering volume on GPU
    void GPURender(vtkRenderer *ren, vtkVolume *vol);

    // Description:
    // Not implemented
    virtual void PreRender(vtkRenderer* vtkNotUsed(ren),
                           vtkVolume* vtkNotUsed(vol),
                           double vtkNotUsed(datasetBounds)[6],
                           double vtkNotUsed(scalarRange)[2],
                           int vtkNotUsed(numberOfScalarComponents),
                           unsigned int vtkNotUsed(numberOfLevels)) {};

    // Description:
    // Empty implementation.
    virtual void RenderBlock(vtkRenderer* vtkNotUsed(ren),
                             vtkVolume* vtkNotUsed(vol),
                             unsigned int vtkNotUsed(level)) {};

    // Description:
    // Empty implementation.
    virtual void PostRender(vtkRenderer* vtkNotUsed(ren),
                            int vtkNotUsed(umberOfScalarComponents)) {};

    // Description:
    // Empty implementation.
    void GetReductionRatio(double vtkNotUsed(ratio)[3]) {};

    // Description:
    // Empty implementation.
    virtual int IsRenderSupported(vtkRenderWindow *vtkNotUsed(window),
                                  vtkVolumeProperty *vtkNotUsed(property))
      {
      return 1;
      }

    class vtkInternal;
    vtkInternal* Impl;
private:
    // Not implemented.
    vtkOpenGLGPUVolumeRayCastMapper(const vtkOpenGLGPUVolumeRayCastMapper&);

    // Not implemented.
    void operator=(const vtkOpenGLGPUVolumeRayCastMapper&);
};

#endif // __vtkOpenGLGPUVolumeRayCastMapper_h
