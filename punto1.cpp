#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada
    // Se carga la imagen desde una ruta especificada en el disco duro. La imagen se lee en escala de grises (cv::IMREAD_GRAYSCALE)
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/tutor.png", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Aplicar binarización con un umbral
    cv::Mat binariaImage;
    // cv::THRESH_BINARY Los píxeles con un valor mayor o igual a 128 se establecen en 255 (blanco), y los demás en 0 (negro).
    cv::threshold(inputImage, binariaImage, 128, 255, cv::THRESH_BINARY);

    // Aplicar una dilatación para engrosar el texto
    // Un kernel es una pequeña matriz que se desliza sobre la imagen y define cómo se aplicará una transformación.
    // cv::MORPH_RECT crea un kernel de forma rectangular de 5x5 píxeles.
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::Mat binarizacionDilatada;
    // cv::dilate toma la imagen binaria de entrada, aplica el kernel definido y guarda el resultado en thickenedImage.
    cv::dilate(binariaImage, binarizacionDilatada, kernel);

    // Guardar la imagen resultante
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Binarizacion_Dilatacion.png", binarizacionDilatada);

    // Mostrar las imágenes
    cv::imshow("Original", inputImage);
    cv::imshow("Binarizada y Engrosada", binarizacionDilatada);
    cv::waitKey(0);

    return 0;
}
