#include "../include/Receipt.hpp"

/**
 * @brief Read and process image
 *
 * Reads the image from image and converts to black and white
 *
 * @param imagePath path to the receipt image
 */
void Receipt::preprocessImage(const std::string &imagePath)
{
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    cv::threshold(image, image, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imwrite("receipts/preprocessed/preprocessed_receipt.png", image);
}

/**
 * @brief extracts text from the image.
 *
 * Takes the pre processed image and extracts text
 *
 * @param imagePath path to the receipt image
 * @return text that was recognized
 */
std::string Receipt::extractText(const std::string &imagePath)
{
    tesseract::TessBaseAPI tess;
    tess.Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
    tess.SetPageSegMode(tesseract::PSM_AUTO);

    PIX *image = pixRead(imagePath.c_str());
    tess.SetImage(image);
    char *outText = tess.GetUTF8Text();

    std::string text(outText);
    delete[] outText;
    pixDestroy(&image);

    return text;
}
