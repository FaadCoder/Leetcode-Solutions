/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
    
    bool isValidFont(string text, int font, int w, int h, FontInfo fontInfo)
    {
        long long int width = 0;
        int height = fontInfo.getHeight(font);
        
        for(char &ch:text)
            width += fontInfo.getWidth(font,ch);
            
        
        return width<=w and height<=h;
    }
    
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        sort(begin(fonts),end(fonts));
        
        int low = 0;
        int high = fonts.size()-1;
        int maxFontRes = -1;
        while(low<=high)
        {
            int mid = low + ((high-low)>>1);
            if(isValidFont(text,fonts[mid],w,h,fontInfo))
            {
                maxFontRes = fonts[mid];
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return maxFontRes;
    }
};