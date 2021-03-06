#ifndef test_pubmed_q5_huffman_
#define test_pubmed_q5_huffman_

#include "../fastr_index.hpp"
#include "../global_vars.hpp"

#define NUM_THREADS 1
#define BUFFER_POOL_SIZE 1

using namespace std;

static double* R;
static int* RC;

static int* doc1_col0_huffman_tree_array;
static bool* doc1_col0_huffman_terminator_array;

static int* term_col0_huffman_tree_array;
static bool* term_col0_huffman_terminator_array;

static int* term_col1_huffman_tree_array;
static bool* term_col1_huffman_terminator_array;

static int* doc2_col0_huffman_tree_array;
static bool* doc2_col0_huffman_terminator_array;

static int* doc2_col1_huffman_tree_array;
static bool* doc2_col1_huffman_terminator_array;

static int* year_col0_huffman_tree_array;
static bool* year_col0_huffman_terminator_array;

static int* author2_col0_huffman_tree_array;
static bool* author2_col0_huffman_terminator_array;

extern inline void test_pubmed_q5_huffman_doc1_col0_decode_Huffman(unsigned char* doc1_col0_ptr, int32_t doc1_col0_bytes, int32_t & doc1_fragment_size) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_term_col0_decode_Huffman(unsigned char* term_col0_ptr, int32_t term_col0_bytes, int32_t & term_fragment_size) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_term_col1_decode_Huffman(unsigned char* term_col1_ptr, int32_t term_fragment_size) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_doc2_col0_decode_Huffman(unsigned char* doc2_col0_ptr, int32_t doc2_col0_bytes, int32_t & doc2_fragment_size) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_doc2_col1_decode_Huffman(unsigned char* doc2_col1_ptr, int32_t doc2_fragment_size) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_year_col0_decode_Huffman(unsigned char* year_col0_ptr, uint32_t & year_col0_element) __attribute__((always_inline));

extern inline void test_pubmed_q5_huffman_author2_col0_decode_Huffman(unsigned char* author2_col0_ptr, int32_t author2_col0_bytes, int32_t & author2_fragment_size) __attribute__((always_inline));

void test_pubmed_q5_huffman_doc1_col0_decode_Huffman(unsigned char* doc1_col0_ptr, int32_t doc1_col0_bytes, int32_t & doc1_fragment_size) {

	bool* terminate_start = &(doc1_col0_huffman_terminator_array[0]);
	int* tree_array_start = &(doc1_col0_huffman_tree_array[0]);

	int mask = 0x100;

	while (doc1_col0_bytes > 1) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *doc1_col0_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				doc1_col0_ptr++;
				doc1_col0_bytes--;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[0][0][0][0][doc1_fragment_size++] = *tree_array;
	}

	if (mask != 0x100) {
		int bit_pos = mask;
		unsigned char last_byte = *doc1_col0_ptr;
		while (bit_pos > 1) {
			unsigned char bit = last_byte & (bit_pos >>= 1);
			if (bit) {
				bool* terminator_array = terminate_start;
				int* tree_array = tree_array_start;

				while (!*terminator_array) {
					char direction = *doc1_col0_ptr & (mask >>= 1);

					terminator_array += *tree_array;
					tree_array += *tree_array;

					if (direction) {
						terminator_array++;
						tree_array++;
					}
				}

				buffer_arrays[0][0][0][0][doc1_fragment_size++] = *tree_array;
				bit_pos = mask;
			}
		}
	}
}

void test_pubmed_q5_huffman_term_col0_decode_Huffman(unsigned char* term_col0_ptr, int32_t term_col0_bytes, int32_t & term_fragment_size) {

	bool* terminate_start = &(term_col0_huffman_terminator_array[0]);
	int* tree_array_start = &(term_col0_huffman_tree_array[0]);

	int mask = 0x100;

	while (term_col0_bytes > 1) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *term_col0_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				term_col0_ptr++;
				term_col0_bytes--;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[2][0][0][0][term_fragment_size++] = *tree_array;
	}

	if (mask != 0x100) {
		int bit_pos = mask;
		unsigned char last_byte = *term_col0_ptr;
		while (bit_pos > 1) {
			unsigned char bit = last_byte & (bit_pos >>= 1);
			if (bit) {
				bool* terminator_array = terminate_start;
				int* tree_array = tree_array_start;

				while (!*terminator_array) {
					char direction = *term_col0_ptr & (mask >>= 1);

					terminator_array += *tree_array;
					tree_array += *tree_array;

					if (direction) {
						terminator_array++;
						tree_array++;
					}
				}

				buffer_arrays[2][0][0][0][term_fragment_size++] = *tree_array;
				bit_pos = mask;
			}
		}
	}
}

void test_pubmed_q5_huffman_term_col1_decode_Huffman(unsigned char* term_col1_ptr, int32_t term_fragment_size) {

	bool* terminate_start = &(term_col1_huffman_terminator_array[0]);
	int* tree_array_start = &(term_col1_huffman_tree_array[0]);

	int mask = 0x100;

	for (int32_t i=0; i<term_fragment_size; i++) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *term_col1_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				term_col1_ptr++;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[2][1][0][0][i] = *tree_array;
	}
}

void test_pubmed_q5_huffman_doc2_col0_decode_Huffman(unsigned char* doc2_col0_ptr, int32_t doc2_col0_bytes, int32_t & doc2_fragment_size) {

	bool* terminate_start = &(doc2_col0_huffman_terminator_array[0]);
	int* tree_array_start = &(doc2_col0_huffman_tree_array[0]);

	int mask = 0x100;

	while (doc2_col0_bytes > 1) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *doc2_col0_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				doc2_col0_ptr++;
				doc2_col0_bytes--;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[3][0][0][0][doc2_fragment_size++] = *tree_array;
	}

	if (mask != 0x100) {
		int bit_pos = mask;
		unsigned char last_byte = *doc2_col0_ptr;
		while (bit_pos > 1) {
			unsigned char bit = last_byte & (bit_pos >>= 1);
			if (bit) {
				bool* terminator_array = terminate_start;
				int* tree_array = tree_array_start;

				while (!*terminator_array) {
					char direction = *doc2_col0_ptr & (mask >>= 1);

					terminator_array += *tree_array;
					tree_array += *tree_array;

					if (direction) {
						terminator_array++;
						tree_array++;
					}
				}

				buffer_arrays[3][0][0][0][doc2_fragment_size++] = *tree_array;
				bit_pos = mask;
			}
		}
	}
}

void test_pubmed_q5_huffman_doc2_col1_decode_Huffman(unsigned char* doc2_col1_ptr, int32_t doc2_fragment_size) {

	bool* terminate_start = &(doc2_col1_huffman_terminator_array[0]);
	int* tree_array_start = &(doc2_col1_huffman_tree_array[0]);

	int mask = 0x100;

	for (int32_t i=0; i<doc2_fragment_size; i++) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *doc2_col1_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				doc2_col1_ptr++;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[3][1][0][0][i] = *tree_array;
	}
}

void test_pubmed_q5_huffman_year_col0_decode_Huffman(unsigned char* year_col0_ptr, uint32_t & year_col0_element) {

	int mask = 0x100;
	bool* terminator_array = &(year_col0_huffman_terminator_array[0]);
	int* tree_array = &(year_col0_huffman_tree_array[0]);

	while(!*terminator_array) {

		char direction = *year_col0_ptr & (mask >>= 1);

		if (mask == 1) {
			mask = 0x100;
			year_col0_ptr++;
		}

		terminator_array += *tree_array;
		tree_array += *tree_array;

		if (direction) {
			terminator_array++;
			tree_array++;
		}
	}

	year_col0_element = *tree_array;
}

void test_pubmed_q5_huffman_author2_col0_decode_Huffman(unsigned char* author2_col0_ptr, int32_t author2_col0_bytes, int32_t & author2_fragment_size) {

	bool* terminate_start = &(author2_col0_huffman_terminator_array[0]);
	int* tree_array_start = &(author2_col0_huffman_tree_array[0]);

	int mask = 0x100;

	while (author2_col0_bytes > 1) {

		bool* terminator_array = terminate_start;
		int* tree_array = tree_array_start;

		while(!*terminator_array) { 

			char direction = *author2_col0_ptr & (mask >>= 1);

			if (mask == 1) { 
				mask = 0x100;
				author2_col0_ptr++;
				author2_col0_bytes--;
			}

			terminator_array += *tree_array;
			tree_array += *tree_array;

			if (direction) {
				terminator_array++;
				tree_array++;
			}
		}

		buffer_arrays[4][0][0][0][author2_fragment_size++] = *tree_array;
	}

	if (mask != 0x100) {
		int bit_pos = mask;
		unsigned char last_byte = *author2_col0_ptr;
		while (bit_pos > 1) {
			unsigned char bit = last_byte & (bit_pos >>= 1);
			if (bit) {
				bool* terminator_array = terminate_start;
				int* tree_array = tree_array_start;

				while (!*terminator_array) {
					char direction = *author2_col0_ptr & (mask >>= 1);

					terminator_array += *tree_array;
					tree_array += *tree_array;

					if (direction) {
						terminator_array++;
						tree_array++;
					}
				}

				buffer_arrays[4][0][0][0][author2_fragment_size++] = *tree_array;
				bit_pos = mask;
			}
		}
	}
}

extern "C" double* test_pubmed_q5_huffman(int** null_checks) {

	benchmark_t1 = chrono::steady_clock::now();

	int max_frag;

	max_frag = metadata.idx_max_fragment_sizes[0];
	for(int i=0; i<metadata.idx_num_encodings[0]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[0][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[0][i][j][k] = new int[max_frag];
			}
		}
	}

	max_frag = metadata.idx_max_fragment_sizes[1];
	for(int i=0; i<metadata.idx_num_encodings[1]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[1][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[1][i][j][k] = new int[max_frag];
			}
		}
	}

	max_frag = metadata.idx_max_fragment_sizes[2];
	for(int i=0; i<metadata.idx_num_encodings[2]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[2][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[2][i][j][k] = new int[max_frag];
			}
		}
	}

	max_frag = metadata.idx_max_fragment_sizes[3];
	for(int i=0; i<metadata.idx_num_encodings[3]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[3][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[3][i][j][k] = new int[max_frag];
			}
		}
	}

	max_frag = metadata.idx_max_fragment_sizes[4];
	for(int i=0; i<metadata.idx_num_encodings[4]; i++) {
		for (int j=0; j<NUM_THREADS; j++) {
			buffer_arrays[4][i][j] = new int*[BUFFER_POOL_SIZE];
			for (int k=0; k<BUFFER_POOL_SIZE; k++) {
				buffer_arrays[4][i][j][k] = new int[max_frag];
			}
		}
	}

	RC = new int[metadata.idx_domains[4][0]]();
	R = new double[metadata.idx_domains[4][0]]();


	doc1_col0_huffman_tree_array = idx[0]->huffman_tree_array[0];
	doc1_col0_huffman_terminator_array = idx[0]->huffman_terminator_array[0];

	term_col0_huffman_tree_array = idx[2]->huffman_tree_array[0];
	term_col0_huffman_terminator_array = idx[2]->huffman_terminator_array[0];

	term_col1_huffman_tree_array = idx[2]->huffman_tree_array[1];
	term_col1_huffman_terminator_array = idx[2]->huffman_terminator_array[1];

	doc2_col0_huffman_tree_array = idx[3]->huffman_tree_array[0];
	doc2_col0_huffman_terminator_array = idx[3]->huffman_terminator_array[0];

	doc2_col1_huffman_tree_array = idx[3]->huffman_tree_array[1];
	doc2_col1_huffman_terminator_array = idx[3]->huffman_terminator_array[1];

	year_col0_huffman_tree_array = idx[1]->huffman_tree_array[0];
	year_col0_huffman_terminator_array = idx[1]->huffman_terminator_array[0];

	author2_col0_huffman_tree_array = idx[4]->huffman_tree_array[0];
	author2_col0_huffman_terminator_array = idx[4]->huffman_terminator_array[0];

	int64_t author1_list[1];
	author1_list[0] = 1000;

	for (int author1_it = 0; author1_it<1; author1_it++) {

		int64_t author1_col0_element = author1_list[author1_it];

		uint32_t* row_doc1 = idx[0]->index_map[author1_col0_element];
		int32_t doc1_col0_bytes = idx[0]->index_map[author1_col0_element+1][0] - row_doc1[0];
		if(doc1_col0_bytes) {

			unsigned char* doc1_col0_ptr = &(idx[0]->fragment_data[0][row_doc1[0]]);
			int32_t doc1_fragment_size = 0;
			test_pubmed_q5_huffman_doc1_col0_decode_Huffman(doc1_col0_ptr, doc1_col0_bytes, doc1_fragment_size);

			for (int32_t doc1_it = 0; doc1_it < doc1_fragment_size; doc1_it++) {

				uint32_t doc1_col0_element = buffer_arrays[0][0][0][0][doc1_it];

				uint32_t* row_term = idx[2]->index_map[doc1_col0_element];
				int32_t term_col0_bytes = idx[2]->index_map[doc1_col0_element+1][0] - row_term[0];
				if(term_col0_bytes) {

					unsigned char* term_col0_ptr = &(idx[2]->fragment_data[0][row_term[0]]);
					int32_t term_fragment_size = 0;
					test_pubmed_q5_huffman_term_col0_decode_Huffman(term_col0_ptr, term_col0_bytes, term_fragment_size);

					unsigned char* term_col1_ptr = &(idx[2]->fragment_data[1][row_term[1]]);
					test_pubmed_q5_huffman_term_col1_decode_Huffman(term_col1_ptr, term_fragment_size);

					for (int32_t term_it = 0; term_it < term_fragment_size; term_it++) {

						uint32_t term_col0_element = buffer_arrays[2][0][0][0][term_it];
						unsigned char term_col1_element = buffer_arrays[2][1][0][0][term_it];

						uint32_t* row_doc2 = idx[3]->index_map[term_col0_element];
						int32_t doc2_col0_bytes = idx[3]->index_map[term_col0_element+1][0] - row_doc2[0];
						if(doc2_col0_bytes) {

							unsigned char* doc2_col0_ptr = &(idx[3]->fragment_data[0][row_doc2[0]]);
							int32_t doc2_fragment_size = 0;
							test_pubmed_q5_huffman_doc2_col0_decode_Huffman(doc2_col0_ptr, doc2_col0_bytes, doc2_fragment_size);

							unsigned char* doc2_col1_ptr = &(idx[3]->fragment_data[1][row_doc2[1]]);
							test_pubmed_q5_huffman_doc2_col1_decode_Huffman(doc2_col1_ptr, doc2_fragment_size);

							for (int32_t doc2_it = 0; doc2_it < doc2_fragment_size; doc2_it++) {

								uint32_t doc2_col0_element = buffer_arrays[3][0][0][0][doc2_it];
								unsigned char doc2_col1_element = buffer_arrays[3][1][0][0][doc2_it];

								uint32_t* row_year = idx[1]->index_map[doc2_col0_element];

								unsigned char* year_col0_ptr = &(idx[1]->fragment_data[0][row_year[0]]);
								uint32_t year_col0_element;
								test_pubmed_q5_huffman_year_col0_decode_Huffman(year_col0_ptr, year_col0_element);

								uint32_t* row_author2 = idx[4]->index_map[doc2_col0_element];
								int32_t author2_col0_bytes = idx[4]->index_map[doc2_col0_element+1][0] - row_author2[0];
								if(author2_col0_bytes) {

									unsigned char* author2_col0_ptr = &(idx[4]->fragment_data[0][row_author2[0]]);
									int32_t author2_fragment_size = 0;
									test_pubmed_q5_huffman_author2_col0_decode_Huffman(author2_col0_ptr, author2_col0_bytes, author2_fragment_size);

									for (int32_t author2_it = 0; author2_it < author2_fragment_size; author2_it++) {
										uint32_t author2_col0_element = buffer_arrays[4][0][0][0][author2_it];

										RC[author2_col0_element] = 1;
										R[author2_col0_element] += (double)(term_col1_element*doc2_col1_element)/(2017-year_col0_element);
									}
								}
							}
						}
					}
				}
			}
		}
	}


	for (int j=0; j<metadata.idx_num_encodings[0]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[0][j][k][l];
			}
			delete[] buffer_arrays[0][j][k];
		}
	}
	for (int j=0; j<metadata.idx_num_encodings[1]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[1][j][k][l];
			}
			delete[] buffer_arrays[1][j][k];
		}
	}
	for (int j=0; j<metadata.idx_num_encodings[2]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[2][j][k][l];
			}
			delete[] buffer_arrays[2][j][k];
		}
	}
	for (int j=0; j<metadata.idx_num_encodings[3]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[3][j][k][l];
			}
			delete[] buffer_arrays[3][j][k];
		}
	}
	for (int j=0; j<metadata.idx_num_encodings[4]; j++) {
		for (int k=0; k<NUM_THREADS; k++) {
			for (int l=0; l<BUFFER_POOL_SIZE; l++) {
				delete[] buffer_arrays[4][j][k][l];
			}
			delete[] buffer_arrays[4][j][k];
		}
	}


	*null_checks = RC;
	return R;

}

#endif

