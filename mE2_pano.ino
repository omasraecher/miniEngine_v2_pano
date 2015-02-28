/*

    Author: Christoph Hoeft
        
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

// 2015-02-11 CH define pano mode vars

#define PANO_MODE_AUTO  B00000001
#define PANO_MODE_MAN   B00000010

uint8_t pano_mode   = PANO_MODE_AUTO;
uint16_t h_angle	= 360;
uint16_t v_angle	= 180;

//  hypothenuse (Bildkreis) berechnen
// =runden(Wurzel((ccd_length*ccd_length)+(ccd_width*ccd_width));2)  //ohne das mal 100 durch 100
// =runden((100*Wurzel((ccd_length*ccd_length)+(ccd_width*ccd_width))/100);2)  //mit dem mal 100 durch 100


// Calculate field of view of normal lens using the entered image length 
// f_utilization_value = 100% ( bedeutet Bildausnutzung ist 100% )
//f_NormFOVlength_value = (round(100*((360 / PI) * (atan((f_utilization_value / 100.0 * f_length_value) / (2 * f_focalLength_value))))))/100

// Calculate field of view of fisheye lens using the entered image length 
// f_utilization_value = 100% ( bedeutet Bildausnutzung ist 100% )
//f_FishFOVlength.value = (round(100*((360 / PI) * (asin(((f_utilization_value/100 * f_length_value)/2)/(2 * f_focalLength_value)))*2)))/100

// Calculate field of view of normal lens using the entered image width 
// f_utilization_value = 100% ( bedeutet Bildausnutzung ist 100% )
//f_NormFOVwidth_value = (round(100*((360 / PI) * (atan((f_utilization_value / 100.0 * f_width_value) / (2 * f_focalLength_value))))))/100

// Calculate field of view of fisheye lens using the entered image width 
// f_utilization_value = 100% ( bedeutet Bildausnutzung ist 100% )
//f_FishFOVwidth_value = (round(100*((360 / PI) * (asin(((f_utilization_value/100 * f_width_value)/2)/(2 * f_focalLength_value)))*2)))/100

// Calculate diagonal field of view of normal lens using the calculated image hypothenuse
//f_NormFOVdiam_value = (round(100*((360 / PI)*(atan((f_utilization_value / 100.0 * f_diam_value) / (2 * f_focalLength_value))))))/100

// Calculate diagonal field of view of fisheye lens using the calculated image hypothenuse 
//f_FishFOVdiam_value = (round(100*((360 / PI) * (asin(((f_utilization_value/100 * f_diam_value) / 2) / (2*f_focalLength_value))) * 2))) / 100

// Calculate the number of images needed with the fiheye lens to 
// reach the entered field of view using the entered overlap and 
// landscape orientation 
// Overlap is calculated as a percentage of the field of view 
//f_FishImNrLandscape_value = round(10 * (f_FishDesPanAngle_value/(f_FishFOVlength_value - ((f_FishOverlap_value/100) * f_FishFOVlength_value)))) / 10

// Calculate the number of images needed with the fiheye lens to 
// reach the entered field of view using the entered overlap and 
// portrait orientation
// Overlap is calculated as a percentage of the field of view
//f_FishImNrPortrait_value = round(10 * (f_FishDesPanAngle_value/(f_FishFOVwidth_value - ((f_FishOverlap_value/100) * f_FishFOVwidth_value))))/10

// Calculate the number of images needed with the normal lens to 
// reach the entered field of view using the entered overlap and 
// landscape orientation
// Overlap is calculated as a percentage of the field of view
//f_NormImNrLandscape_value = round(10 * (f_NormDesPanAngle_value/(f_NormFOVlength_value - ((f_NormOverlap_value/100) * f_NormFOVlength_value)))) / 10

// Calculate the number of images needed with the normal lens to 
// reach the entered field of view using the entered overlap and 
// landscape orientation
// Overlap is calculated as a percentage of the field of view
//f_NormImNrPortrait_value = round(10 * (f_NormDesPanAngle_value/(f_NormFOVwidth_value - ((f_NormOverlap_value/100) * f_NormFOVwidth_value))))/10

// Calculate the percentage of overlap using a fisheye lens and 
// the entered number of images in portrait orientation
// Overlap is a percentage of the field of view
//f_FishOverlapPo_value = round( 100 * (((f_FishGivenNrImages_value * f_FishFOVwidth_value) - f_FishDesPanAngle_value) / f_FishGivenNrImages_value) / f_FishFOVwidth_value)

// Calculate the percentage of overlap using a fisheye lens and 
// the entered number of images in landscape orientation
// Overlap is a percentage of the field of view
//f_FishOverlapLa_value = round( 100 * (((f_FishGivenNrImages_value * f_FishFOVlength_value) - f_FishDesPanAngle_value) / f_FishGivenNrImages_value) / f_FishFOVlength_value

// Calculate the number of images needed with the normal lens 
// to reach the entered field of view using the entered overlap 
// and portrait orientation-->
// Overlap is calculated as a percentage of the field of view
//f_NormOverlapPo_value = round( 100 * (((f_NormGivenNrImages_value * f_NormFOVwidth_value) - f_NormDesPanAngle_value) /f_NormGivenNrImages_value) / f_NormFOVwidth_value

// Calculate the percentage of overlap using a normal lens and 
// the entered number of images in landscape orientation
// Overlap is a percentage of the field of view
//f_NormOverlapLa_value = round( 100 * (((f_NormGivenNrImages_value * f_NormFOVlength_value) - f_NormDesPanAngle_value) /f_NormGivenNrImages_value) / f_NormFOVlength_value)
