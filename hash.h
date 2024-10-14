// 💡 This class performs the double SHA-256 hash
class CHash256 {
    private:
        CSHA256 sha;  // 🔒 SHA-256 machine for hashing once
    
    public:
        // 💡 Output size is 32 bytes (256 bits)
        static const size_t OUTPUT_SIZE = CSHA256::OUTPUT_SIZE;
    
        // 🚀 This function performs the double SHA-256
        void Finalize(Span<unsigned char> output) {
            unsigned char buf[CSHA256::OUTPUT_SIZE];  // Buffer to store the first hash
            
            // Step 1: First SHA-256
            sha.Finalize(buf);
            
            // Step 2: Second SHA-256 using the output from Step 1
            sha.Reset().Write(buf, CSHA256::OUTPUT_SIZE).Finalize(output.data());
        }
    
        // 📝 This function adds data to the SHA-256 machine
        CHash256& Write(Span<const unsigned char> input) {
            sha.Write(input.data(), input.size());  // Add the input data
            return *this;
        }
    
        // 🔄 Reset the SHA-256 machine
        CHash256& Reset() {
            sha.Reset();  // Start fresh
            return *this;
        }
    };









