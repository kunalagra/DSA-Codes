#include <stdio.h>
#include <string.h>

struct entry_s {
	char not_empty;
	char key[7];
	char val[16];
};

typedef struct entry_s entry_t;

struct ht_s {
	int size;
	struct entry_s *tab;	
};

typedef struct ht_s ht_t;


/* Create a new ht. */
ht_t *ht_create(int size) {
	ht_t *ht = NULL;
	int i;

	if (size < 1) return NULL;

	/* Allocate the tab itself. */
	if ((ht = malloc(sizeof(ht_t))) == NULL )
		return NULL;
	/* Allocate pointers to the head nodes. */
	if ((ht->tab = malloc(sizeof( entry_t) * size)) == NULL)
		return NULL;
	for (i = 0; i < size; i++)
		memset(&ht->tab[i], 0, sizeof(entry_t));

	ht->size = size;
	return ht;	
}

/* Hash a string for a particular hash tab. */
int ht_hash( ht_t *ht, char *key ) {
	unsigned int hv;
	int i = 0;

	/* Convert our string to an integer */
	while (i < strlen(key)) {
		hv += key[i];
		i++;
	}
	return hv % ht->size;
}

/* Insert a key-val pair into a hash tab. */
void ht_set(ht_t *ht, char *key, char *val) {
	int ind = ht_hash(ht, key), i = ind;

	for (; i < ht -> size; i++)
		if (!ht->tab[i].not_empty) {
			ht->tab[i].not_empty = 1;
			strcpy(ht->tab[i].key, key);
			strcpy(ht->tab[i].val, val);
			return;
		}
	for (i = 0; i < ind; i++)
		if (!ht->tab[i].not_empty) {
			ht->tab[i].not_empty = 1;
			strcpy(ht->tab[i].key, key);
			strcpy(ht->tab[i].val, val);
			return;
		}
}

/* Retrieve a key-val pair from a hash tab. */
char *ht_get(ht_t *ht, char *key) {
	int ind = ht_hash(ht, key), i = ind;

	for (; i < ht->size; i++)
		if ((ht->tab[i].not_empty) && !strcmp(ht->tab[i].key, key))
			return ht->tab[i].val;
	for (i = 0; i < ind; i++)
		if ((ht->tab[i].not_empty) && !strcmp(ht->tab[i].key, key))
			return ht->tab[i].val;
	return "not found";	
}
void ht_del(ht_t *hashtable, char *key){
    
    int bin = 0;
    int flag =0;
    
    entry_t *temp,*pair;
    
    bin = ht_hash (hashtable,key);
    
    pair = hashtable->tab[bin]; // Go to index node
   
    temp = pair;
    while(pair != NULL) {
        if(strcmp(key,pair->key) == 0 ){
            flag = 1;
            if(pair == hashtable->tab[bin]){
                hashtable->tab[bin] = pair->next;
            }
            else{
                temp->next = pair->next;
            }
            free(pair);
            break;
        }
        temp = pair;
        pair = pair->next;
    }
    if (flag){
        printf("Data deleted successfully from Hash Table\n");
    }
    else{
        printf("Given data is not present in hash table!!!!\n");
    }
}

int main(void) {

	ht_t *ht = ht_create(4);

	ht_set(ht, "key1", "inky");
	ht_set(ht, "key2", "pinky");
	ht_set(ht, "key3", "blinky");
	ht_set(ht, "kez2", "floyd");

	printf( "%s\n", ht_get( ht, "key1" ) );
	printf( "%s\n", ht_get( ht, "key2" ) );
	printf( "%s\n", ht_get( ht, "key3" ) );
	printf( "%s\n", ht_get( ht, "kez2" ) );
	printf( "%s\n", ht_get( ht, "key4" ) );

	return 0;
}