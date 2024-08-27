#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/imagenBGR.png");
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Separar los canales BGR
    std::vector<cv::Mat> channels(3);
    // cv::Mat donde se almacenarán los tres canales separados.
    // cv::split(): Esta función separa una imagen en sus canales de color individuales.
    cv::split(inputImage, channels);

    // Crear imágenes vacías para los canales combinados con negro (8 bits por canal)
    // cv::Mat::zeros(): Crea una matriz (imagen) llena de ceros
    // inputImage.size(): Devuelve las dimensiones de la imagen de entrada (ancho x alto).
    // inputImage.type(): Devuelve el tipo de la imagen, es decir, el tipo de datos y la cantidad de canales (en este caso, 8 bits por canal y 3 canales BGR).
    cv::Mat redChannel = cv::Mat::zeros(inputImage.size(), inputImage.type());
    cv::Mat greenChannel = cv::Mat::zeros(inputImage.size(), inputImage.type());
    cv::Mat blueChannel = cv::Mat::zeros(inputImage.size(), inputImage.type());

    // Rellenar los canales de color asignando el canal correspondiente
    // Los otros dos canales permanecen en negro (0)
    // std::vector<cv::Mat>: Se utiliza para crear un vector de matrices de OpenCV (cv::Mat).
    std::vector<cv::Mat> red = {cv::Mat::zeros(inputImage.size(), CV_8UC1), cv::Mat::zeros(inputImage.size(), CV_8UC1), channels[2]};
    std::vector<cv::Mat> green = {cv::Mat::zeros(inputImage.size(), CV_8UC1), channels[1], cv::Mat::zeros(inputImage.size(), CV_8UC1)};
    std::vector<cv::Mat> blue = {channels[0], cv::Mat::zeros(inputImage.size(), CV_8UC1), cv::Mat::zeros(inputImage.size(), CV_8UC1)};

    // Combinar los canales para formar imágenes de color
    // cv::merge(): Combina varios canales individuales en una sola imagen de múltiples canales.
    cv::merge(red, redChannel);
    cv::merge(green, greenChannel);
    cv::merge(blue, blueChannel);

    // Guardar cada canal como una imagen separada
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Red_Channel.png", redChannel);
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Green_Channel.png", greenChannel);
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Blue_Channel.png", blueChannel);

    // Mostrar la imagen original y los canales de color
    cv::imshow("Imagen Original", inputImage);
    cv::imshow("Canal Rojo", redChannel);
    cv::imshow("Canal Verde", greenChannel);
    cv::imshow("Canal Azul", blueChannel);
    cv::waitKey(0);

    return 0;
}
