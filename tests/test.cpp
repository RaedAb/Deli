/**
 * Here I am going to test the image recognition and text extraction of opencv and tesseract.
*/

#include <iostream>
#include "../include/Receipt.hpp"

int main()
{
    Receipt test;
    std::string receiptImagePath = "receipts/raw/receipt2.jpg";

    test.preprocessImage(receiptImagePath);
    std::string text = test.extractText("receipts/preprocessed/preprocessed_receipt.png");

    std::cout << text << std::endl;
}