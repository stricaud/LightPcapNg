#include <stdlib.h>

#include <light_blocks.h>
#include <light_platform.h>
#include <light_util.h>

light_custom_block_t *light_custom_block_new(void)
{
	light_custom_block_t *cb;

	cb = malloc(sizeof(light_custom_block_t));

	cb->block_type = PCAPNG_CUSTOM_DATA_BLOCK;
	cb->block_total_length = 0;
	cb->pen = 0;

	return cb;
}

void light_custom_block_free(light_custom_block_t *cb)
{
	free(cb);
}

/* void light_custom_block_write(light_pcapng_t *pcapng, light_custom_block_t *cb) */
void light_custom_block_write(light_pcapng_t *pcapng, void *data, size_t datalen)
{
	light_custom_block_t cb;

	PADD32(datalen, &datalen);

	cb.block_type = PCAPNG_CUSTOM_DATA_BLOCK;
	cb.block_total_length = sizeof(light_custom_block_t) + datalen + sizeof(uint32_t);
	cb.pen = 123;

	light_write(pcapng->file, &cb, sizeof(cb));

	light_write(pcapng->file, data, datalen);

	light_write(pcapng->file, &cb.block_total_length, sizeof(cb.block_total_length));

	/* uint32_t options = 0; */
	/* char *data = "hello"; */
	/* uint32_t block_type = cb->block_type; */
	/* uint32_t block_total_len = cb->block_total_length; */
	/* uint32_t pen = cb->pen; */

	/* light_write(pcapng->file, &block_type, sizeof(uint32_t)); */
	/* light_write(pcapng->file, &block_total_len, sizeof(uint32_t)); */
	/* light_write(pcapng->file, &pen, sizeof(uint32_t)); */

	/* light_write(pcapng->file, data, 5); */

	/* /\* light_write(pcapng->file, &options, sizeof(uint32_t)); *\/ */
	/* light_write(pcapng->file, swap32(cb->block_total_length), sizeof(uint32_t)); */
}
