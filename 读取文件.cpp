
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

// ���� 1
std::vector<unsigned char> readFromFile1(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    std::vector<unsigned char> result;
    if (file == nullptr) {
        return result;
    }

    // ��ȡ�ļ���С������һ�ζ���
    size_t fileSize = getFileSize(file);
    if (fileSize != 0) {
        result.resize(fileSize);
        size_t n = fread(&result[0], 1, fileSize, file);
        assert(n <= fileSize);
        if (n != fileSize) {
            result.resize(n);
        }
    }

    // �ڶ�ȡ���̵��У��п����ļ���С�б仯���ٳ��Զ�ȡ
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

// ���� 2
std::vector<unsigned char> readFromFile2(const char* filePath) {
    std::ifstream inputFile(filePath, std::ios::binary);
    std::vector<unsigned char> fileData((std::istreambuf_iterator<char>(inputFile)),
                                        std::istreambuf_iterator<char>());
    return fileData;
}

// ���� 3���ڷ��� 2 �����ϵ��� reserve
std::vector<unsigned char> readFromFile3(const char* filePath) {
    std::vector<unsigned char> fileData;
    fileData.reserve(getFileSize(filePath));
    
    std::ifstream inputFile(filePath, std::ios::binary);
    fileData.insert(fileData.end(),
                    std::istreambuf_iterator<char>(inputFile),
                    std::istreambuf_iterator<char>());
    
    return fileData;
}

// ���� 4��˼·ͬ���� 1�� ֻ�ǻ��� ifstream ʵ�֣�û�п����������ֻ�����ٶ�
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
    const char* filePath = "/��Ӱ/[�����Ӱwww.ygdy8.com].ʹͽ����.BD.720p.����˫������.mkv";
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
