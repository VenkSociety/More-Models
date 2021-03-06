#include "Common.h"
static struct ModelPart screen, stem, base;

static void TVModel_MakeParts(void) {
	BoxDesc_BuildBox(&screen, &(struct BoxDesc) {
		BoxDesc_Tex(0, 0),
		BoxDesc_Box(-24,10,-1, 24,35,1) 
	});

	BoxDesc_BuildBox(&stem, &(struct BoxDesc) {
		BoxDesc_Tex(7, 34), 
		BoxDesc_Box(-4,4,-1, 4,10,1) 
	});

	BoxDesc_BuildBox(&base, &(struct BoxDesc) {
		BoxDesc_Tex(30, 31), 
		BoxDesc_Box(-10,0,-3, 10,4,3)
	});
}

static void TVModel_Draw(struct Entity *e) {
	Model_ApplyTexture(e);
	Models.uScale = 1/128.0f; Models.vScale = 1/128.0f;

	Model_DrawPart(&screen);
	Model_DrawPart(&stem);
	Model_DrawPart(&base);

	Model_UpdateVB();
}

static float TVModel_GetNameY(struct Entity *e) { e; return 2.25f; }
static float TVModel_GetEyeY(struct Entity *e) { e; return 1.50f; }
static void TVModel_GetSize(struct Entity *e)   { _SetSize(14,14,14); }
static void TVModel_GetBounds(struct Entity *e) { _SetBounds(-5,0,-2, 5,16,2); }

static struct ModelVertex vertices[MODEL_BOX_VERTICES * 5];
static struct Model model = {
	"tv", vertices, &tv_tex,
	TVModel_MakeParts, TVModel_Draw,
	TVModel_GetNameY,  TVModel_GetEyeY,
	TVModel_GetSize,   TVModel_GetBounds
};

struct Model* TVModel_GetInstance(void) {
	Model_Init(&model);
	return &model;
}