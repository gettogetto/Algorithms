
#include <fstream>
#include <vector>
#include <cassert>
//#include <boost/progress.hpp>

static size_t getFileSize(FILE* file) {
    fseek(file, 0, SEEK_END);
    size_t read_len = ftell(file);
    fseek(file, 0, SEEK_SET);
    return read_len;
}

static size_t getFileSize(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (file == nullptr) {
        return 0;
    }
    size_t size = getFileSize(file);
    fclose(file);
    return size;
}

// 方法 1
std::vector<unsigned char> readFromFile1(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    std::vector<unsigned char> result;
    if (file == nullptr) {
        return result;
    }

    // 获取文件大小，尽量一次读完
    size_t fileSize = getFileSize(file);
    if (fileSize != 0) {
        result.resize(fileSize);
        size_t n = fread(&result[0], 1, fileSize, file);
        assert(n <= fileSize);
        if (n != fileSize) {
            result.resize(n);
        }
    }

    // 在读取过程当中，有可能文件大小有变化，再尝试读取
    const size_t read_len = 1024;
    char buf[read_len];
    for (;;) {
        size_t n = fread(buf, 1, read_len, file);
        result.insert(result.end(), buf, buf + n);
        if (n < read_len) {
            break;
        }
    }
    fclose(file);
    return result;
}

// 方法 2
std::vector<unsigned char> readFromFile2(const char* filePath) {
    std::ifstream inputFile(filePath, std::ios::binary);
    std::vector<unsigned char> fileData((std::istreambuf_iterator<char>(inputFile)),
                                        std::istreambuf_iterator<char>());
    return fileData;
}

// 方法 3，在方法 2 基础上调用 reserve
std::vector<unsigned char> readFromFile3(const char* filePath) {
    std::vector<unsigned char> fileData;
    fileData.reserve(getFileSize(filePath));
    
    std::ifstream inputFile(filePath, std::ios::binary);
    fileData.insert(fileData.end(),
                    std::istreambuf_iterator<char>(inputFile),
                    std::istreambuf_iterator<char>());
    
    return fileData;
}

// 方法 4，思路同方法 1， 只是换了 ifstream 实现，没有考意外情况，只测量速度
std::vector<unsigned char> readFromFile4(const char* filePath) {
    std::vector<unsigned char> fileData;
    std::ifstream inputFile(filePath, std::ios::binary);
    inputFile.seekg(0, std::ios::end);
    fileData.resize(inputFile.tellg());
    inputFile.seekg(0);
    inputFile.read(reinterpret_cast<char*>(fileData.data()), fileData.size());
    return fileData;
}


int main(int argc, const char* argv[]) {
    const char* filePath = "/电影/[阳光电影www.ygdy8.com].使徒行者.BD.720p.国粤双语中字.mkv";
    {
       // boost::progress_timer t;
        readFromFile1(filePath);
    }
    
    {
      //  boost::progress_timer t;
        readFromFile2(filePath);
    }
    
    {
      //  boost::progress_timer t;
        readFromFile3(filePath);
    }

    {
       // boost::progress_timer t;
        readFromFile4(filePath);
    }

    return 0;
}
