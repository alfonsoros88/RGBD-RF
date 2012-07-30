# include "TrainData.h"


TrainData :: TrainData () 
{
    pixelC = vector <PixelInfo> ();
}

/**
 * Creates an empty vector of trainImgNum x numPixels
 */
 //CHECK
TrainData :: TrainData (int trainImgNum, int numPixels)
{
    pixelC = vector <PixelInfo> (trainImgNum * numPixels);
    cout << "TAMAÑO RANK != 0 " << pixelC.size() << endl;
}

/**
 * Selects random pixels from the image imgId
 * numImg --> size subset of images
 */
 // CHECK
TrainData :: TrainData (int numPixels,
                        ImagePool& imgPool,
                        int startIdx,
                        int endIdx,
                        bool byLabel)
{
    int j;
    int imgIdx;
    Coord coord;
    vector <PixelInfo> pix;
    
    // iterates through image pool and get numImg subset of
    // them, then takes numPixels from the current image
    for (imgIdx = startIdx; imgIdx <= endIdx; imgIdx++) {

        if (byLabel == true) {
            imgPool[imgIdx].getRandCoordByLabel(numPixels, pix, imgIdx);
            pixelC.insert(pixelC.end(), pix.begin(), pix.end());

        }
        else {
            for (j = 0; j < numPixels; j++) {
                coord = imgPool[imgIdx].getRandomCoord();
                pixelC.push_back( PixelInfo(coord, imgIdx) );
            }
        }
    }
    cout << "TAMAÑO RANK = 0 " << pixelC.size() << endl;
/*
    for (int i = 0; i < trainImgNum; i++) {

        imgIdx = rand() % imgPool.poolSize();

        if (byLabel == true) {
            imgPool[imgIdx].getRandCoordByLabel(numPixels, pix, imgIdx);
            pixelC.insert(pixelC.end(), pix.begin(), pix.end());

        }
        else {
            for (j = 0; j < numPixels; j++) {
                coord = imgPool[imgIdx].getRandomCoord();
                pixelC.push_back( PixelInfo(coord, imgIdx) );
            }
        }
    }
*/

}

/**
 * Returns the number of pixels
 */
int TrainData :: size ()
{
    return pixelC.size();
}