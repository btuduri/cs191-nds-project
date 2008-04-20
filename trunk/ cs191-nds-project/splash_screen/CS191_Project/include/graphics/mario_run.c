//-----------------------------------------------------------------
// mario_run.c
// 
// Created by spritemaker.py at 2008-04-19 03:43:34.851000
// spritemaker.py by Dean Nevins
//-----------------------------------------------------------------
const unsigned short mario_runPalette[256] =
    {
    0x7C1F, 0x001F, 0x009C, 0x0098, 0x0010, 0x0094, 0x2118, 0x6318, 
    0x4298, 0x2094, 0x4214, 0x4218, 0x2098, 0x2198, 0x5294, 0x0088, 
    0x6378, 0x008C, 0x0090, 0x431C, 0x429C, 0x439C, 0x2190, 0x2194, 
    0x2218, 0x4210, 0x210C, 0x2104, 0x2214, 0x629C, 0x4104, 0x418C, 
    0x0110, 0x221C, 0x219C, 0x2084, 0x0114, 0x0000, 0x4194, 0x229C, 
    0x6000, 0x4190, 0x400C, 0x7C00, 0x4000, 0x2018, 0x2110, 0x6088, 
    0x6004, 0x7BFF, 0x7FFF, 0x2014, 0x2010, 0x201C, 0x2108, 0x4010, 
    0x218C, 0x2000, 0x6008, 0x6310, 0x2008, 0x6084, 0x4108, 0x2210, 

    0x2114, 0x031C, 0x0318, 0x4008, 0x018C, 0x410C, 0x2090, 0x0214, 
    0x0298, 0x4084, 0x0210, 0x4088, 0x2004, 0x0190, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    };

const unsigned short mario_runBitmap[4096] =
    {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0300, 0x0303, 0x0000, 0x0000, 0x0300, 0x0303, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 
    0x0000, 0x0000, 0x0101, 0x0101, 0x0203, 0x0101, 0x0101, 0x0101, 
    0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0000, 0x0000, 0x0000, 0x0101, 0x0201, 0x0000, 0x0000, 
    0x0101, 0x0201, 0x0003, 0x0000, 0x0302, 0x0707, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0400, 0x0303, 0x0000, 0x0000, 0x0400, 0x0304, 
    0x0000, 0x0000, 0x0F00, 0x1111, 0x0000, 0x0000, 0x1111, 0x1511, 
    0x0000, 0x0F00, 0x110F, 0x1511, 0x0000, 0x0F0F, 0x0F0F, 0x1511, 
    0x0000, 0x0F0F, 0x0F0F, 0x1311, 0x0000, 0x0000, 0x0F28, 0x140F, 

    0x0102, 0x0201, 0x0202, 0x0202, 0x0202, 0x0202, 0x0303, 0x0303, 
    0x1211, 0x1312, 0x1313, 0x0214, 0x1515, 0x1312, 0x1313, 0x0814, 
    0x1515, 0x2212, 0x1313, 0x1E1D, 0x1315, 0x0512, 0x1314, 0x2919, 
    0x1315, 0x1313, 0x1413, 0x140A, 0x1414, 0x1414, 0x1C14, 0x0818, 

    0x0703, 0x0003, 0x0000, 0x0000, 0x0307, 0x0010, 0x0000, 0x0000, 
    0x0101, 0x0001, 0x0000, 0x0000, 0x0101, 0x0001, 0x0000, 0x0000, 
    0x0000, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x1513, 0x0015, 0x0000, 0x0000, 0x1513, 0x0013, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x1900, 0x0000, 0x0000, 0x0000, 0x1F00, 

    0x0000, 0x3328, 0x0102, 0x1601, 0x0000, 0x0133, 0x0201, 0x0104, 
    0x2C00, 0x3132, 0x0502, 0x3501, 0x070E, 0x3131, 0x0110, 0x0101, 
    0x1019, 0x1031, 0x0E07, 0x190E, 0x070E, 0x0707, 0x0E0E, 0x1919, 
    0x1919, 0x0E0E, 0x190E, 0x2C2C, 0x1F1F, 0x1919, 0x2819, 0x2C2C, 

    0x1616, 0x1717, 0x2517, 0x1725, 0x162B, 0x1616, 0x0F16, 0x0716, 
    0x2B2B, 0x1601, 0x1016, 0x0E07, 0x2B2B, 0x1002, 0x0710, 0x0E07, 
    0x2B2B, 0x0E03, 0x070E, 0x190E, 0x2B28, 0x3603, 0x0E38, 0x190E, 
    0x2828, 0x0005, 0x0000, 0x0000, 0x2C2C, 0x002C, 0x0000, 0x0000, 

    0x0808, 0x0018, 0x0000, 0x0000, 0x171C, 0x0000, 0x0000, 0x0000, 
    0x0019, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x3600, 0x0000, 0x1100, 0x4040, 0x0046, 
    0x0000, 0x1200, 0x4040, 0x4040, 0x0000, 0x4000, 0x4040, 0x4040, 
    0x0000, 0x0000, 0x0909, 0x4646, 0x0000, 0x0000, 0x0000, 0x4646, 
    0x0000, 0x0000, 0x0000, 0x4600, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x3838, 0x1F1F, 0x2828, 0x2C39, 0x3628, 0x2C2C, 0x2C2C, 0x3939, 
    0x2828, 0x3939, 0x0F39, 0x1212, 0x2828, 0x3939, 0x3939, 0x0F0F, 
    0x282C, 0x2828, 0x2828, 0x0F0F, 0x2C46, 0x2C2C, 0x002C, 0x0000, 
    0x4646, 0x112C, 0x0000, 0x0000, 0x1212, 0x0F11, 0x0000, 0x0000, 

    0x2C2C, 0x002C, 0x0000, 0x0000, 0x3939, 0x3939, 0x0000, 0x0000, 
    0x0946, 0x4040, 0x0000, 0x0000, 0x400F, 0x4640, 0x0012, 0x0000, 
    0x0F0F, 0x460F, 0x1112, 0x0000, 0x0F0F, 0x0F0F, 0x1112, 0x0000, 
    0x0F00, 0x0F0F, 0x110F, 0x0000, 0x0000, 0x0F00, 0x000F, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0300, 0x0303, 0x0000, 0x0000, 0x0400, 0x0303, 
    0x0000, 0x0000, 0x0400, 0x0304, 0x0000, 0x0000, 0x0F00, 0x0404, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0200, 0x0101, 0x0101, 0x0203, 0x0102, 0x0101, 0x0101, 
    0x0102, 0x0101, 0x0101, 0x0101, 0x0102, 0x0101, 0x0101, 0x0101, 
    0x0102, 0x0201, 0x0202, 0x0202, 0x0203, 0x0303, 0x0303, 0x0303, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0001, 0x0000, 0x0000, 0x0101, 0x0101, 0x0000, 0x0000, 
    0x0101, 0x0101, 0x0002, 0x0000, 0x0201, 0x0302, 0x0007, 0x0000, 
    0x0302, 0x0607, 0x0007, 0x0000, 0x0B05, 0x1003, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x1100, 0x1111, 0x0000, 0x0000, 0x110F, 0x1511, 
    0x0000, 0x0F0F, 0x110F, 0x1511, 0x0F00, 0x0F0F, 0x0F0F, 0x1111, 
    0x0000, 0x0000, 0x0F0F, 0x130F, 0x0000, 0x2800, 0x0102, 0x1C0F, 
    0x0000, 0x0128, 0x0101, 0x2D01, 0x3231, 0x0101, 0x0201, 0x3301, 

    0x1211, 0x1412, 0x1313, 0x0314, 0x1515, 0x1812, 0x1313, 0x1714, 
    0x1515, 0x1212, 0x1313, 0x1914, 0x1315, 0x1212, 0x1322, 0x2314, 
    0x1315, 0x2713, 0x1413, 0x0F08, 0x1818, 0x1818, 0x2518, 0x081C, 
    0x1616, 0x1C17, 0x2517, 0x1C25, 0x162B, 0x1616, 0x2E16, 0x0725, 

    0x0203, 0x0010, 0x0000, 0x0000, 0x0101, 0x0101, 0x0000, 0x0000, 
    0x001A, 0x0100, 0x0000, 0x0000, 0x001C, 0x0000, 0x0000, 0x0000, 
    0x0013, 0x0000, 0x0000, 0x0000, 0x1513, 0x0015, 0x0000, 0x0000, 
    0x1308, 0x0008, 0x0000, 0x0000, 0x0B1C, 0x0017, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x3200, 0x3232, 0x0000, 0x0000, 0x1000, 0x1031, 
    0x0000, 0x0000, 0x0700, 0x0707, 0x0000, 0x1212, 0x1919, 0x0E0E, 
    0x0000, 0x3640, 0x1F38, 0x1919, 0x0000, 0x4040, 0x3840, 0x1F38, 
    0x0000, 0x4609, 0x2C46, 0x3836, 0x0000, 0x4600, 0x1212, 0x2828, 

    0x3232, 0x0131, 0x0104, 0x3301, 0x1010, 0x0710, 0x0101, 0x2A01, 
    0x0707, 0x0707, 0x0207, 0x3002, 0x0E0E, 0x0E0E, 0x2828, 0x3D28, 
    0x1919, 0x2819, 0x2828, 0x4129, 0x191F, 0x282C, 0x2828, 0x4142, 
    0x3939, 0x2C2C, 0x2C2C, 0x484B, 0x3928, 0x2C39, 0x2C2C, 0x282C, 

    0x302B, 0x1602, 0x3116, 0x0707, 0x302B, 0x0703, 0x0707, 0x0707, 
    0x372B, 0x1903, 0x1919, 0x0E07, 0x031C, 0x0005, 0x0038, 0x0E00, 
    0x0342, 0x0004, 0x0000, 0x0000, 0x2841, 0x0028, 0x0000, 0x0000, 
    0x2B28, 0x282B, 0x0028, 0x0000, 0x2828, 0x2B28, 0x2828, 0x1212, 

    0x0E07, 0x000E, 0x0000, 0x0000, 0x0E0E, 0x0000, 0x0000, 0x0000, 
    0x190E, 0x0000, 0x0000, 0x0000, 0x0019, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0946, 0x0009, 0x0000, 0x0000, 

    0x0000, 0x1200, 0x1212, 0x2C2C, 0x0000, 0x0000, 0x1111, 0x3939, 
    0x0000, 0x0000, 0x1111, 0x1111, 0x0000, 0x0000, 0x1111, 0x0F11, 
    0x0000, 0x0000, 0x0F00, 0x000F, 0x0000, 0x0000, 0x0000, 0x000F, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x2C2C, 0x3939, 0x2C39, 0x2C2C, 0x3939, 0x0000, 0x0000, 0x3939, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x2828, 0x2B28, 0x112B, 0x0912, 0x2C2C, 0x282C, 0x1211, 0x0946, 
    0x2C39, 0x112C, 0x1211, 0x4612, 0x3900, 0x112C, 0x1111, 0x1212, 
    0x0000, 0x0F0F, 0x1111, 0x0000, 0x0000, 0x0F0F, 0x0000, 0x0000, 
    0x0000, 0x000F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0909, 0x4040, 0x0000, 0x0000, 0x0909, 0x0000, 0x0000, 0x0000, 
    0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0500, 0x0303, 
    0x0000, 0x0000, 0x0500, 0x0203, 0x0000, 0x0000, 0x0400, 0x0305, 
    0x0000, 0x0000, 0x0400, 0x0304, 0x0000, 0x0000, 0x0F00, 0x110F, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0101, 
    0x0203, 0x0101, 0x0101, 0x0101, 0x0102, 0x0101, 0x0101, 0x0101, 
    0x0102, 0x0101, 0x0101, 0x0101, 0x0102, 0x0101, 0x0202, 0x0202, 
    0x0203, 0x0202, 0x0303, 0x0303, 0x1211, 0x1212, 0x1313, 0x0313, 

    0x0001, 0x0000, 0x0000, 0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0101, 0x0000, 0x0000, 0x0101, 0x0101, 0x0002, 0x0000, 
    0x0101, 0x0602, 0x0007, 0x0000, 0x0303, 0x0308, 0x0000, 0x0000, 
    0x0703, 0x020C, 0x0000, 0x0000, 0x0202, 0x0001, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x1111, 0x1511, 0x0000, 0x0F00, 0x110F, 0x1511, 
    0x0000, 0x0F0F, 0x0F0F, 0x1111, 0x0000, 0x0F0F, 0x0F0F, 0x110F, 
    0x0000, 0x0000, 0x0F28, 0x0F0F, 0x0000, 0x2A00, 0x0102, 0x0101, 
    0x0000, 0x0328, 0x0202, 0x0101, 0x3100, 0x0105, 0x0101, 0x0101, 

    0x1515, 0x1212, 0x1313, 0x0B13, 0x1515, 0x1212, 0x1313, 0x0813, 
    0x1515, 0x1212, 0x1306, 0x1B13, 0x1313, 0x2413, 0x1413, 0x1A14, 
    0x1414, 0x1414, 0x2514, 0x0808, 0x1716, 0x1717, 0x1A1C, 0x1725, 
    0x162B, 0x1616, 0x1616, 0x2525, 0x2B2B, 0x1601, 0x1616, 0x0E07, 

    0x0116, 0x0101, 0x0000, 0x0000, 0x0017, 0x0100, 0x0001, 0x0000, 
    0x001C, 0x0000, 0x0000, 0x0000, 0x1313, 0x0015, 0x0000, 0x0000, 
    0x1313, 0x0015, 0x0000, 0x0000, 0x1418, 0x0008, 0x0000, 0x0000, 
    0x1817, 0x0017, 0x0000, 0x0000, 0x1600, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x1007, 
    0x0000, 0x0000, 0x0700, 0x0707, 0x0000, 0x0000, 0x1900, 0x0E0E, 
    0x0000, 0x0000, 0x1900, 0x1919, 0x0000, 0x0000, 0x3800, 0x1F1F, 
    0x0000, 0x0000, 0x0000, 0x3600, 0x0000, 0x0000, 0x0000, 0x1100, 

    0x3110, 0x3132, 0x0432, 0x0101, 0x1010, 0x3110, 0x0131, 0x2D01, 
    0x0707, 0x0707, 0x2A0E, 0x3302, 0x0E0E, 0x070E, 0x2828, 0x3E28, 
    0x1919, 0x280E, 0x2828, 0x1C30, 0x1919, 0x2C19, 0x2828, 0x3F28, 
    0x3838, 0x2C2C, 0x2B2C, 0x2B2B, 0x3911, 0x3939, 0x2B2C, 0x2B2B, 

    0x2B30, 0x0501, 0x0707, 0x190E, 0x2B2B, 0x0402, 0x0E0E, 0x3819, 
    0x2B28, 0x3C03, 0x190E, 0x0019, 0x3F1C, 0x2305, 0x1F19, 0x0000, 
    0x4141, 0x4443, 0x3638, 0x0000, 0x4242, 0x442C, 0x0000, 0x0000, 
    0x2C4B, 0x0039, 0x0000, 0x0000, 0x392B, 0x0000, 0x0000, 0x0000, 

    0x0038, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x1100, 0x0000, 0x0000, 0x0000, 0x0F00, 
    0x0000, 0x0000, 0x0000, 0x0F00, 0x0000, 0x0000, 0x0000, 0x0F00, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x280F, 0x3939, 0x282C, 0x2B2B, 0x2C2C, 0x282C, 0x2839, 0x2B2B, 
    0x0F0F, 0x0000, 0x2C00, 0x2828, 0x000F, 0x0000, 0x282C, 0x2828, 
    0x0000, 0x3900, 0x2C2C, 0x2C2C, 0x0000, 0x1100, 0x1212, 0x4009, 
    0x0000, 0x1111, 0x1212, 0x4046, 0x0000, 0x110F, 0x1211, 0x4046, 

    0x002B, 0x0000, 0x0000, 0x0000, 0x002B, 0x0000, 0x0000, 0x0000, 
    0x0028, 0x0000, 0x0000, 0x0000, 0x0028, 0x0000, 0x0000, 0x0000, 
    0x4646, 0x4646, 0x0000, 0x0000, 0x4040, 0x4640, 0x0000, 0x0000, 
    0x4040, 0x4640, 0x0000, 0x0000, 0x4040, 0x0009, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0300, 
    0x0000, 0x0000, 0x0303, 0x0203, 0x0000, 0x0000, 0x0303, 0x0203, 
    0x0000, 0x0000, 0x0504, 0x0303, 0x0000, 0x0000, 0x0404, 0x0305, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0101, 
    0x0000, 0x0102, 0x0101, 0x0101, 0x0202, 0x0101, 0x0101, 0x0101, 
    0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 0x0101, 
    0x0102, 0x0201, 0x0202, 0x0302, 0x0202, 0x0302, 0x0303, 0x0503, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0001, 0x0000, 0x0000, 0x0101, 0x0201, 0x0003, 0x0000, 
    0x0101, 0x0702, 0x0000, 0x0000, 0x0302, 0x0707, 0x0000, 0x0000, 
    0x030D, 0x0007, 0x0000, 0x0000, 0x0707, 0x0010, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0F0F, 0x110F, 0x0000, 0x0000, 0x1111, 0x1511, 
    0x0000, 0x0F00, 0x1111, 0x1511, 0x0000, 0x0F0F, 0x0F0F, 0x1511, 
    0x0F00, 0x0F0F, 0x0F0F, 0x110F, 0x0000, 0x0000, 0x0F0F, 0x140F, 
    0x0000, 0x2800, 0x0101, 0x1601, 0x0000, 0x0328, 0x0102, 0x1003, 

    0x1211, 0x1412, 0x1313, 0x1714, 0x1515, 0x0612, 0x1313, 0x0814, 
    0x1515, 0x1212, 0x1313, 0x1E1D, 0x1515, 0x1212, 0x1424, 0x2508, 
    0x1515, 0x1813, 0x1C13, 0x1418, 0x1414, 0x1414, 0x2508, 0x1816, 
    0x1616, 0x1717, 0x2E17, 0x2525, 0x1610, 0x1616, 0x1616, 0x0016, 

    0x0101, 0x0001, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x1313, 0x0015, 0x0000, 0x0000, 
    0x1513, 0x0015, 0x0000, 0x0000, 0x1513, 0x0013, 0x0000, 0x0000, 
    0x081C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x032A, 0x0202, 0x1010, 0x2800, 0x0305, 0x1010, 0x3110, 
    0x2800, 0x1028, 0x3110, 0x3131, 0x282C, 0x0728, 0x1010, 0x3131, 
    0x2C2C, 0x3628, 0x070E, 0x0707, 0x2C2C, 0x2828, 0x0E0E, 0x0E0E, 
    0x2C39, 0x2C2C, 0x1919, 0x1919, 0x3900, 0x2C2C, 0x3838, 0x3838, 

    0x2B10, 0x1601, 0x3216, 0x0000, 0x2B31, 0x073A, 0x0E07, 0x0000, 
    0x2831, 0x073A, 0x0007, 0x0000, 0x2810, 0x0E30, 0x0019, 0x0000, 
    0x1607, 0x0045, 0x0000, 0x0000, 0x420E, 0x0048, 0x0000, 0x0000, 
    0x4819, 0x0048, 0x0000, 0x0000, 0x1A38, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4600, 
    0x0000, 0x0000, 0x0000, 0x4600, 0x0000, 0x0000, 0x0000, 0x4612, 

    0x3900, 0x3939, 0x2B28, 0x2B2B, 0x0000, 0x3939, 0x2B28, 0x2B2B, 
    0x0000, 0x0000, 0x2B28, 0x2B2B, 0x0000, 0x3939, 0x282C, 0x2B2B, 
    0x0000, 0x2C2C, 0x2828, 0x2828, 0x2E2E, 0x4046, 0x4040, 0x4640, 
    0x2E2E, 0x4046, 0x4040, 0x4640, 0x2E2E, 0x4046, 0x4040, 0x4640, 

    0x2B2C, 0x0000, 0x0000, 0x0000, 0x002C, 0x0000, 0x0000, 0x0000, 
    0x002B, 0x0000, 0x0000, 0x0000, 0x0028, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0046, 0x0000, 0x0000, 0x0000, 0x1246, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 
    0x0000, 0x0000, 0x0300, 0x0203, 0x0000, 0x0000, 0x0000, 0x0303, 
    0x0000, 0x0000, 0x0000, 0x0304, 0x0000, 0x0000, 0x0000, 0x0404, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 
    0x0000, 0x0104, 0x0101, 0x0101, 0x0202, 0x0101, 0x0101, 0x0101, 
    0x0102, 0x0101, 0x0101, 0x0101, 0x0202, 0x0101, 0x0101, 0x0101, 
    0x0203, 0x0102, 0x0201, 0x0202, 0x0305, 0x0202, 0x0303, 0x0303, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0101, 0x0000, 0x0000, 0x0101, 0x0101, 0x0003, 0x0000, 
    0x0101, 0x0101, 0x0302, 0x0000, 0x0101, 0x0301, 0x0009, 0x0000, 
    0x0202, 0x0E03, 0x0003, 0x0000, 0x0505, 0x0708, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x110F, 0x0000, 0x0000, 0x1100, 0x1111, 
    0x0000, 0x0F00, 0x0F0F, 0x1111, 0x0000, 0x0F0F, 0x0F0F, 0x110F, 
    0x0000, 0x0F00, 0x0F0F, 0x0F0F, 0x0000, 0x0000, 0x2B28, 0x0F2B, 
    0x0000, 0x2800, 0x2F2B, 0x0101, 0x0000, 0x2800, 0x0134, 0x0101, 

    0x1111, 0x0311, 0x1312, 0x1414, 0x1511, 0x1515, 0x1412, 0x1414, 
    0x1311, 0x1513, 0x1212, 0x1414, 0x1311, 0x1513, 0x1212, 0x0814, 
    0x1311, 0x1313, 0x0D0E, 0x0814, 0x080F, 0x0808, 0x0E07, 0x0F25, 
    0x1601, 0x1716, 0x0707, 0x2507, 0x3503, 0x0716, 0x1010, 0x0707, 

    0x0308, 0x0102, 0x0000, 0x0000, 0x1618, 0x0101, 0x0001, 0x0000, 
    0x001F, 0x0000, 0x0000, 0x0000, 0x0023, 0x0000, 0x0000, 0x0000, 
    0x1313, 0x1515, 0x0000, 0x0000, 0x130B, 0x1315, 0x0000, 0x0000, 
    0x0817, 0x1C13, 0x0000, 0x0000, 0x1700, 0x001C, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x4600, 0x0000, 0x0000, 0x0000, 0x4646, 0x4640, 

    0x2C00, 0x0328, 0x0202, 0x0301, 0x2C00, 0x3028, 0x0202, 0x0504, 
    0x2800, 0x2828, 0x3428, 0x0411, 0x2C00, 0x2828, 0x2828, 0x332B, 
    0x2C39, 0x282C, 0x2828, 0x282B, 0x2C39, 0x2C2C, 0x2828, 0x2828, 
    0x3900, 0x2C2C, 0x2C2C, 0x2C2C, 0x2C00, 0x3939, 0x2C2B, 0x2C2C, 

    0x3101, 0x3131, 0x3131, 0x1031, 0x3103, 0x3131, 0x3132, 0x0710, 
    0x0705, 0x3131, 0x1031, 0x0E07, 0x1902, 0x0E19, 0x0E07, 0x190E, 
    0x3628, 0x3836, 0x0E19, 0x0019, 0x4928, 0x4736, 0x3800, 0x001F, 
    0x492C, 0x4747, 0x462C, 0x0000, 0x2C2C, 0x2C1A, 0x3939, 0x1246, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x460F, 0x4040, 0x0000, 0x0000, 0x4600, 0x4040, 
    0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 0x0000, 0x0000, 0x4000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x2800, 0x2839, 0x2B2B, 0x392B, 0x2840, 0x282B, 0x2B2B, 0x392B, 
    0x4040, 0x2B2B, 0x2B2B, 0x0028, 0x4040, 0x2840, 0x2828, 0x0028, 
    0x4040, 0x1146, 0x0000, 0x0000, 0x460F, 0x1112, 0x0000, 0x0000, 
    0x1200, 0x0F11, 0x0000, 0x0000, 0x0000, 0x0F00, 0x0000, 0x0000, 

    0x2C2C, 0x2C2C, 0x4039, 0x4640, 0x3939, 0x3939, 0x4040, 0x4640, 
    0x0000, 0x0000, 0x4000, 0x4640, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0011, 0x0000, 0x0000, 0x0000, 0x0011, 0x0000, 0x0000, 0x0000, 
    0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0103, 0x0205, 0x0101, 0x0101, 0x0101, 
    0x0202, 0x0101, 0x0101, 0x0101, 0x0203, 0x0102, 0x0101, 0x0101, 
    0x0304, 0x0203, 0x0102, 0x0101, 0x0404, 0x0305, 0x0202, 0x0201, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0001, 0x0000, 
    0x0101, 0x0101, 0x0001, 0x0000, 0x0101, 0x0101, 0x0101, 0x0002, 
    0x0101, 0x0101, 0x0101, 0x0302, 0x0101, 0x0101, 0x0101, 0x0302, 
    0x0202, 0x0202, 0x0502, 0x0E04, 0x0303, 0x0303, 0x0404, 0x0005, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x1100, 0x0000, 0x0000, 0x0000, 0x110F, 
    0x0000, 0x0000, 0x0F0F, 0x0F0F, 0x0000, 0x0000, 0x0F0F, 0x0F0F, 
    0x0000, 0x0000, 0x0000, 0x0F28, 0x0000, 0x0000, 0x2800, 0x2B28, 
    0x0000, 0x0E0E, 0x2828, 0x012B, 0x0000, 0x2C0E, 0x2B28, 0x0102, 

    0x1111, 0x1111, 0x1211, 0x1412, 0x1111, 0x1111, 0x1515, 0x1815, 
    0x1111, 0x1111, 0x1513, 0x2012, 0x110F, 0x1111, 0x1513, 0x1112, 
    0x0F0F, 0x1111, 0x1313, 0x1814, 0x0F2B, 0x080F, 0x1414, 0x0808, 
    0x0101, 0x1601, 0x1716, 0x1017, 0x0401, 0x0103, 0x0716, 0x1016, 

    0x1414, 0x0504, 0x0303, 0x0000, 0x1414, 0x1618, 0x0102, 0x0000, 
    0x1414, 0x000A, 0x0100, 0x0001, 0x0822, 0x0026, 0x0000, 0x0000, 
    0x0E0E, 0x1313, 0x0015, 0x0000, 0x0707, 0x1313, 0x0015, 0x0000, 
    0x1007, 0x0807, 0x0013, 0x0000, 0x3110, 0x0710, 0x0008, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3600, 
    0x0000, 0x0000, 0x0000, 0x3600, 0x0000, 0x4000, 0x4040, 0x2800, 
    0x0000, 0x4000, 0x4609, 0x2800, 0x0000, 0x4000, 0x4646, 0x2B12, 
    0x0000, 0x4600, 0x4646, 0x2B12, 0x0000, 0x0000, 0x1212, 0x2812, 

    0x1900, 0x2C39, 0x3328, 0x0101, 0x3636, 0x282C, 0x2828, 0x0130, 
    0x3636, 0x282C, 0x2828, 0x2D28, 0x3636, 0x282C, 0x2828, 0x2828, 
    0x3928, 0x2C2C, 0x282C, 0x2828, 0x2B2B, 0x2B2B, 0x2C2C, 0x2828, 
    0x2B2B, 0x2B2B, 0x2B2B, 0x2C2C, 0x2828, 0x2828, 0x2C28, 0x2C2C, 

    0x0401, 0x0203, 0x1001, 0x3132, 0x1101, 0x0404, 0x0703, 0x3210, 
    0x0101, 0x0F02, 0x1919, 0x070E, 0x022B, 0x0303, 0x1F36, 0x1919, 
    0x2828, 0x2C28, 0x1C47, 0x0038, 0x2828, 0x1A28, 0x284A, 0x0028, 
    0x2C2C, 0x4A2C, 0x2B4A, 0x2C28, 0x392C, 0x4C2C, 0x2828, 0x2828, 

    0x3131, 0x1031, 0x000E, 0x0000, 0x3131, 0x0731, 0x0019, 0x0000, 
    0x1010, 0x0E07, 0x0000, 0x0000, 0x070E, 0x0E0E, 0x0000, 0x0000, 
    0x3800, 0x1919, 0x0000, 0x0000, 0x0000, 0x3800, 0x0000, 0x0000, 
    0x0000, 0x4612, 0x0012, 0x0000, 0x4612, 0x4040, 0x4640, 0x0000, 

    0x0000, 0x0000, 0x1212, 0x2C12, 0x0000, 0x0000, 0x1212, 0x1112, 
    0x0000, 0x0000, 0x1212, 0x1111, 0x0000, 0x0000, 0x1111, 0x0F11, 
    0x0000, 0x0000, 0x0F00, 0x0F0F, 0x0000, 0x0000, 0x0F00, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x2828, 0x2C28, 0x2C2C, 0x3939, 0x2C2C, 0x2C2C, 0x0000, 0x3939, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x3939, 0x2C39, 0x282C, 0x1228, 0x3939, 0x3900, 0x2C2C, 0x462C, 
    0x0000, 0x3900, 0x2C39, 0x1212, 0x0000, 0x0000, 0x1111, 0x1211, 
    0x0000, 0x0000, 0x110F, 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0946, 0x4040, 0x0040, 0x0000, 0x4646, 0x4040, 0x0040, 0x0000, 
    0x4612, 0x0000, 0x0000, 0x0000, 0x0012, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0304, 
    0x0000, 0x0000, 0x0300, 0x0202, 0x0000, 0x0000, 0x0500, 0x0203, 
    0x0000, 0x0000, 0x0400, 0x0305, 0x0000, 0x0000, 0x0400, 0x0404, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 
    0x0000, 0x0103, 0x0101, 0x0101, 0x0102, 0x0101, 0x0101, 0x0101, 
    0x0102, 0x0101, 0x0101, 0x0101, 0x0102, 0x0101, 0x0101, 0x0101, 
    0x0203, 0x0101, 0x0201, 0x0202, 0x0305, 0x0202, 0x0303, 0x0303, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0201, 0x0000, 0x0000, 0x0101, 0x0101, 0x0003, 0x0000, 
    0x0101, 0x0101, 0x0302, 0x0000, 0x0101, 0x0302, 0x000A, 0x0000, 
    0x0202, 0x0509, 0x000C, 0x0000, 0x0405, 0x070B, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0F00, 0x1111, 0x0000, 0x0000, 0x1111, 0x1111, 
    0x0000, 0x0F0F, 0x0F0F, 0x1111, 0x0000, 0x0F0F, 0x0F0F, 0x1111, 
    0x0000, 0x0F00, 0x0F0F, 0x0F0F, 0x0000, 0x2800, 0x2B2B, 0x0F0F, 
    0x0000, 0x2B2C, 0x0130, 0x0101, 0x3600, 0x2B28, 0x0101, 0x0501, 

    0x1111, 0x0311, 0x1303, 0x1414, 0x1511, 0x1515, 0x1312, 0x0814, 
    0x1311, 0x1515, 0x2112, 0x0814, 0x1311, 0x0D15, 0x1212, 0x1914, 
    0x1311, 0x1315, 0x1412, 0x1A14, 0x080F, 0x0814, 0x1808, 0x1819, 
    0x1716, 0x1717, 0x0E1C, 0x170E, 0x2B01, 0x1616, 0x0707, 0x0007, 

    0x0305, 0x0202, 0x0000, 0x0000, 0x000A, 0x0101, 0x0000, 0x0000, 
    0x000F, 0x0000, 0x0000, 0x0000, 0x0017, 0x0000, 0x0000, 0x0000, 
    0x1313, 0x0015, 0x0000, 0x0000, 0x1308, 0x0015, 0x0000, 0x0000, 
    0x081C, 0x0008, 0x0000, 0x0000, 0x1C00, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x4040, 0x0000, 
    0x0000, 0x0000, 0x4640, 0x0046, 0x0000, 0x0000, 0x4609, 0x0046, 
    0x0000, 0x0000, 0x1246, 0x2B12, 0x0000, 0x4600, 0x1212, 0x2B12, 

    0x282C, 0x0228, 0x0102, 0x0504, 0x282C, 0x0328, 0x0102, 0x0404, 
    0x2828, 0x2828, 0x0228, 0x0F01, 0x282C, 0x2828, 0x2828, 0x0237, 
    0x2C2C, 0x2828, 0x2828, 0x2828, 0x2C2C, 0x282C, 0x2828, 0x2828, 
    0x2C39, 0x2C2C, 0x2C2C, 0x2C2C, 0x2828, 0x2B2B, 0x2C2C, 0x2C2C, 

    0x0703, 0x1032, 0x3131, 0x0731, 0x0705, 0x3131, 0x3232, 0x1032, 
    0x0E0F, 0x3107, 0x3131, 0x0710, 0x1903, 0x0E19, 0x0707, 0x1907, 
    0x1F30, 0x1F36, 0x0E0E, 0x1F0E, 0x3828, 0x0047, 0x191F, 0x0019, 
    0x472C, 0x004A, 0x0000, 0x0036, 0x4D2C, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x000E, 0x0000, 0x0000, 0x0000, 
    0x0019, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x1200, 0x1212, 0x2B28, 0x0000, 0x1200, 0x1212, 0x2828, 
    0x0000, 0x1200, 0x1111, 0x2C11, 0x0000, 0x1100, 0x1111, 0x000F, 
    0x0000, 0x1100, 0x0F0F, 0x0000, 0x0000, 0x0F00, 0x0F0F, 0x0000, 
    0x0000, 0x0F00, 0x000F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x2B2B, 0x282B, 0x3928, 0x2C39, 0x2B2B, 0x2828, 0x3928, 0x3939, 
    0x2828, 0x2828, 0x0000, 0x282C, 0x2C00, 0x282C, 0x3900, 0x2C2C, 
    0x0000, 0x0000, 0x3900, 0x3939, 0x0000, 0x0000, 0x1100, 0x4646, 
    0x0000, 0x0000, 0x1100, 0x4612, 0x0000, 0x0000, 0x1100, 0x1212, 

    0x2B2C, 0x0000, 0x0000, 0x0000, 0x2828, 0x0028, 0x0000, 0x0000, 
    0x2C28, 0x122C, 0x0000, 0x0000, 0x2C2C, 0x402C, 0x4640, 0x0000, 
    0x4039, 0x4040, 0x4040, 0x0046, 0x4046, 0x4040, 0x4040, 0x0046, 
    0x4646, 0x4040, 0x0040, 0x0000, 0x0012, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0304, 
    0x0000, 0x0000, 0x0303, 0x0203, 0x0000, 0x0000, 0x0305, 0x0203, 
    0x0000, 0x0000, 0x0504, 0x0303, 0x0000, 0x0000, 0x0404, 0x0504, 

    0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 0x0102, 0x0101, 
    0x0200, 0x0101, 0x0101, 0x0101, 0x0202, 0x0101, 0x0101, 0x0101, 
    0x0101, 0x0101, 0x0101, 0x0101, 0x0102, 0x0101, 0x0101, 0x0101, 
    0x0202, 0x0201, 0x0202, 0x0303, 0x0303, 0x0303, 0x0303, 0x0503, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0101, 0x0000, 0x0000, 0x0000, 
    0x0101, 0x0202, 0x0000, 0x0000, 0x0101, 0x0201, 0x0003, 0x0000, 
    0x0101, 0x0003, 0x0000, 0x0000, 0x0B03, 0x0003, 0x0000, 0x0000, 
    0x0305, 0x0000, 0x0000, 0x0000, 0x0203, 0x0001, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0F0F, 0x110F, 0x0000, 0x0000, 0x1111, 0x1111, 
    0x0000, 0x0F00, 0x110F, 0x1111, 0x0000, 0x0F0F, 0x0F0F, 0x1111, 
    0x0F00, 0x0F0F, 0x0F0F, 0x110F, 0x0000, 0x2C00, 0x2B2B, 0x0F0F, 
    0x0000, 0x2800, 0x0101, 0x1601, 0x0000, 0x3328, 0x0102, 0x0105, 

    0x1111, 0x1212, 0x1313, 0x0D14, 0x1515, 0x1212, 0x1313, 0x0814, 
    0x1515, 0x1212, 0x1312, 0x1B14, 0x1515, 0x1206, 0x1322, 0x0F14, 
    0x1513, 0x1313, 0x1413, 0x0818, 0x1818, 0x1808, 0x0F18, 0x1725, 
    0x1616, 0x1616, 0x1617, 0x2525, 0x2B37, 0x1616, 0x1616, 0x0000, 

    0x0100, 0x0001, 0x0000, 0x0000, 0x0000, 0x0100, 0x0000, 0x0000, 
    0x1515, 0x0000, 0x0000, 0x0000, 0x1313, 0x0015, 0x0000, 0x0000, 
    0x1513, 0x0013, 0x0000, 0x0000, 0x1308, 0x001C, 0x0000, 0x0000, 
    0x181C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x0000, 0x0000, 0x4000, 
    0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x0000, 0x0000, 0x4600, 

    0x2800, 0x0303, 0x0411, 0x3203, 0x2800, 0x0333, 0x0402, 0x3207, 
    0x282C, 0x2828, 0x0E02, 0x3107, 0x282C, 0x2828, 0x1928, 0x0719, 
    0x2C40, 0x2828, 0x1F28, 0x0E38, 0x4640, 0x282C, 0x2828, 0x1928, 
    0x4646, 0x2C2C, 0x282C, 0x1F28, 0x1246, 0x2C2C, 0x2C2C, 0x2C2C, 

    0x2B31, 0x3B3A, 0x1F19, 0x0000, 0x3131, 0x0731, 0x000E, 0x0000, 
    0x3131, 0x0731, 0x000E, 0x0000, 0x0707, 0x0707, 0x000E, 0x0000, 
    0x0E0E, 0x0E0E, 0x000E, 0x0000, 0x1919, 0x1919, 0x0019, 0x0000, 
    0x1F38, 0x001F, 0x0000, 0x0000, 0x3838, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x4600, 0x0000, 0x0000, 0x0000, 0x1200, 
    0x0000, 0x0000, 0x0000, 0x1200, 0x0000, 0x0000, 0x0000, 0x1200, 
    0x0000, 0x0000, 0x0000, 0x1112, 0x0000, 0x0000, 0x0000, 0x1100, 
    0x0000, 0x0000, 0x0000, 0x0F00, 0x0000, 0x0000, 0x0000, 0x0F00, 

    0x1212, 0x392B, 0x2B2B, 0x2C2B, 0x1212, 0x2B2B, 0x2B2B, 0x392B, 
    0x1212, 0x2B28, 0x2B2B, 0x2B2B, 0x1112, 0x2828, 0x2B2B, 0x002B, 
    0x1111, 0x2C0F, 0x2C2C, 0x402C, 0x0F11, 0x3909, 0x2C39, 0x402C, 
    0x0F0F, 0x4040, 0x4040, 0x4040, 0x4612, 0x4646, 0x4040, 0x4040, 

    0x2C2C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0046, 0x0000, 0x0000, 0x0000, 0x1209, 0x0000, 0x0000, 0x0000, 
    0x1240, 0x0000, 0x0000, 0x0000, 0x0040, 0x0000, 0x0000, 0x0000, 

    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    };

