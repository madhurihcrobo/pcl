#ifndef _VTK_QVTKOPENGL_MAINWINDOW_H
#define _VTK_QVTKOPENGL_MAINWINDOW_H

#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCylinderSource.h>
#include <vtkRegularPolygonSource.h>

#include <vtkPolyDataMapper.h>
#include <vtkSmartPointer.h>
#include <vtkMapper.h>
#include <vtkActor.h>
#include <QVTKOpenGLNativeWidget.h>
#include <QVTKInteractorAdapter.h>

#include <QWidget>
#include <QSemaphore>
#include <QSurfaceFormat>
#include <QDebug>
#include <QWidget>
#include <QSemaphore>
#include <QMainWindow>
#include <QLabel>

class QVTKOpenGLWindow :  public QVTKOpenGLNativeWidget
{
    Q_OBJECT
    vtkSmartPointer<vtkRenderWindow> renderWindow;

public:
    explicit QVTKOpenGLWindow(QWidget *parent = 0);
     void SetRenderWindow(vtkRenderWindow* window);
 };
#endif 