#ifndef IMPAudioServerMediaSubsession_hpp
#define IMPAudioServerMediaSubsession_hpp

#include "OnDemandServerMediaSubsession.hh"

class IMPAudioServerMediaSubsession : public OnDemandServerMediaSubsession
{
public:
    static IMPAudioServerMediaSubsession* createNew(
        UsageEnvironment& env,
        int audioChn);

protected:
    IMPAudioServerMediaSubsession(
        UsageEnvironment& env,
        int audioChn);
    virtual ~IMPAudioServerMediaSubsession();

    virtual FramedSource* createNewStreamSource(
        unsigned clientSessionId,
        unsigned& estBitrate);
    virtual RTPSink* createNewRTPSink(
        Groupsock* rtpGroupsock,
        unsigned char rtpPayloadTypeIfDynamic,
        FramedSource* inputSource);

protected:
    virtual char const* getAuxSDPLine(RTPSink* rtpSink, FramedSource* inputSource);

private:
    int audioChn;
    char* fAuxSDPLine = nullptr;
};

#endif // IMPAudioServerMediaSubsession_hpp
