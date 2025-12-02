class Render
{
public:
    void Initialize(const char* path);
    void Update(const char* path);

private:
    

    unsigned char* pixel = NULL;
    unsigned char* pixel_resize = NULL;
    int width = 0;
    int height = 0;
    int bpp = 0;
    int reWidth = 512;
};