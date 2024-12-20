#include "QVTKOpenGLWindow.h"

#ifdef _MSC_VER
#include <vtkAutoInit.h>
#endif

QVTKOpenGLWindow::QVTKOpenGLWindow(QWidget *parent) 
    : QVTKOpenGLNativeWidget(parent)
{


    auto renderer = vtkSmartPointer<vtkRenderer>::New();
    auto window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    this->SetRenderWindow(window.Get());
    window->AddRenderer(renderer);

    QSurfaceFormat surfaceFormat = QSurfaceFormat();
    surfaceFormat.setSamples(4);
    setFormat(surfaceFormat);
        
	this->setEnableHiDPI(true);

    vtkSmartPointer<vtkRegularPolygonSource> poly = vtkSmartPointer<vtkRegularPolygonSource>::New();
    poly->GeneratePolygonOff(); 
    poly->SetNumberOfSides(50);
    poly->SetRadius(1 * 10);
    poly->SetCenter(0, 0, 0);
    poly->SetNormal(0, 1, 0);


    auto cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
    cylinderSource->SetCenter(0.0, 0.0, 0.0);
    cylinderSource->SetRadius(5.0);
    cylinderSource->SetHeight(7.0);
    cylinderSource->SetResolution(100);

    
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(poly->GetOutputPort());
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    renderer->AddActor(actor);

    mapper->SetInputConnection(cylinderSource->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);

    this->update();
    
    window->Render();

}
void QVTKOpenGLWindow::SetRenderWindow(vtkRenderWindow* window)
{
    if (window) {
        this->renderWindow = window; 
        this->renderWindow->SetWindowName("Custom VTK Render Window");
    }
}