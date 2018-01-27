
// Loads and frees images

#include <unordered_map>

class Image {
	public:
		static Image& loadImage(std::string path);
		static std::unordered_map<std::string path, Image> Images;

};
