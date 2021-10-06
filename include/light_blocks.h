#ifndef _LIGHT_BLOCKS_H_
#define _LIGHT_BLOCKS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "light_pcapng_ext.h"
#include "light_pcapng.h"
#include "light_platform.h"
#include "light_internal.h"

#define swap32(x) ((((x) & 0x000000ff) << 24) | (((x) & 0x0000ff00) << 8) | (((x) & 0x00ff0000) >>  8) | (((x) & 0xff000000) >> 24))

/* Hidden from light_pcapng_ext */
struct _light_pcapng_t
{
	light_pcapng pcapng;
	light_pcapng_file_info *file_info;
	light_file file;
};

/*                         1                   2                   3 */
/*     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/*  0 |             Block Type = 0x00000BAD or 0x40000BAD             | */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/*  4 |                      Block Total Length                       | */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/*  8 |                Private Enterprise Number (PEN)                | */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/* 12 /                                                               / */
/*    /                          Custom Data                          / */
/*    /              variable length, padded to 32 bits               / */
/*    /                                                               / */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/*    /                                                               / */
/*    /                      Options (variable)                       / */
/*    /                                                               / */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
/*    |                      Block Total Length                       | */
/*    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */

/* The Custom Block uses the type code 0x00000BAD (2989 in decimal) for a custom block that pcapng re-writers can copy into new files, and the type code 0x40000BAD (1073744813 in decimal) foro one that should not be copied. See {{section_vendor_copy}} for details. */

/* The Custom Block has the following fields: */

/*     Block Type: The block type of the Custom Block is 0x00000BAD or 0x40000BAD, as described previously. */

/*     Block Total Length: total size of this block, as described in {{section_block}}. */

/*     Private Enterprise Number (32 bits): An IANA-assigned Private Enterprise Number identifying the organization which defined the Custom Block. See {{section_vendor_uses}} for details. The PEN MUST be encoded using the same endianness as the Section Header Block it is within the scope of. */

/*     Custom Data: the custom data, padded to a 32 bit boundary. */

/*     Options: optionally, a list of options (formatted according to the rules defined in {{section_opt}}) can be present. Note that custom options for the Custom Block still use the custom option format and type code, as described in {{section_custom_option}}. */

struct _light_custom_block_t {
	uint32_t  block_type;
	uint32_t  block_total_length;
	uint32_t  pen;
} __attribute__((packed));
typedef struct _light_custom_block_t light_custom_block_t;

light_custom_block_t *light_custom_block_new(void);
void light_custom_block_free(light_custom_block_t *cb);
void light_custom_block_write(light_pcapng_t *pcapng, void *data, size_t datalen);
/* void light_custom_block_write(light_pcapng_t *pcapng, light_custom_block_t *cb); */

#ifdef __cplusplus
}
#endif

#endif	/* _LIGHT_BLOCKS_H_ */
